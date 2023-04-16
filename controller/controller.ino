#include <Arduino.h>
#include "src/communication/communication.hpp"
#include "src/encoder.hpp"
#include "src/mpu.hpp"

/* 
Determines the frequency of actuation changes and serial data transmit
Both events are connected because the GUI should show exactly what the controller works with. So a data transmit is always related to a controller update.
However, this value can not be chosen arbitrarily, due to serial baud rate limitations.
According to this table (https://lucidar.me/en/serialib/most-used-baud-rates-table/) using a baud rate of 115200 serial data can be transmitted at a real byte rate of 86.806 µs per byte.
Depending on the size of the outgoing message and the value of UPDATE_INTERVAL_MS, this could lead to asyncronity and the GUI will most likely not be able to interprete the data.
The minimum update interval to not cause the serial buffer to accumulate data due to baud rate limitations can be expressed as message_size_bytes * real_byte_rate 
which for example results in 177,78 ms for a buffer size of 2048 bytes and a baud rate of 115200 bauds. So the update interval must be higher than that.
*/
#define UPDATE_INTERVAL_MS 200

Communication::ReceiveInterface rx_data;
Communication::TransmitInterface tx_data;
Communication::MessageHandler message{ tx_data.msg };
Encoder wheel_position_rad{ ENC_PIN_CHA, ENC_PIN_CHB, encoder_isr, enc_counter, 0.5 * (2 * PI / 360) };
MinSegMPU mpu;

void setup() {
  Serial.begin(115200);  // Baud rate has been increased permanently on the HC-06 bluetooth module to allow for bigger messages
  while (!Serial) {};

  // Sensor setup
  mpu.setup();
  wheel_position_rad.setup();

  // Initial values of RX Interface
  rx_data.control_state = false;
}

void loop() {
  static uint32_t cycle_start_ms = 0;
  bool new_mpu_data = mpu.update();

  if (new_mpu_data && millis() > cycle_start_ms + UPDATE_INTERVAL_MS) {
    cycle_start_ms = millis();

    // Initialize tx interface with sensor readings
    tx_data.wheel.pos_rad = wheel_position_rad();
    tx_data.wheel.pos_deriv_rad_s = wheel_position_rad.derivative();
    tx_data.tilt.angle_deg.from_acc = mpu.tilt_angle_from_acc_deg();
    tx_data.tilt.angle_deg.from_pitch = mpu.tilt_angle_from_euler_deg();
    tx_data.tilt.angle_deriv_deg_s.from_acc = mpu.tilt_angle_from_acc_deg.derivative();
    tx_data.tilt.angle_deriv_deg_s.from_pitch = mpu.tilt_angle_from_euler_deg.derivative();
    tx_data.tilt.vel_deg_s = mpu.tilt_vel_deg_s();

    // Reference controller state
    // double &wheel_pos_rad = tx_data.wheel.pos_rad;
    // double &tilt_angle_deg = ;
    // double &tilt_vel_deg_s = ;


    if (rx_data.control_state) {

    }

    // Finish loop
    Communication::transmit(tx_data);
    message.clear();
    Sensor::cycle_num++;
  }


}

void serialEvent() {
  char buffer[Communication::RX_SERIAL_BUFFER_SIZE]{ 0 };
  union {
    uint16_t integer = 0;
    byte arr[2];
  } msg_len;

  // When data arrives this function blocks the execution on the microcontroller until the entire message was received or until timeout.
  Serial.setTimeout(100);
  if (Serial.find(Communication::PACKET_START_TOKEN)) {
    // When message start was found, read message size information from first two bytes and then read message
    Serial.readBytes(msg_len.arr, 2);
    Serial.readBytes(buffer, msg_len.integer);
    const DeserializationError err = Communication::read(buffer, rx_data);
    if (err) {
      message.append("Deserialization ERROR: Failed with code: ");
      message.append(err.c_str());
      return;
    }

    // React to received data
    if (rx_data.control_state) {
      message.append("Control enabled!");
    } else {
      message.append("Control disabled!");
    }
  }
}
