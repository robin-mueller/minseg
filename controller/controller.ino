#include <Arduino.h>
#include "src/interface/interface.hpp"

ComInterface::RX rx_interface;
ComInterface::TX tx_interface;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
}

void loop() {
  
}

void serialEvent() {
  const DeserializationError err = rx_interface.receive();
  if (err) return;
  
  strlcpy(tx_interface.msg, "TEST", sizeof(tx_interface.msg) / sizeof(*tx_interface.msg));
  tx_interface.controller_state = rx_interface.controller_state;
  tx_interface.transmit();
}
