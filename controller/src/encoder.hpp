#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>
#include "sensor.hpp"

#define ENC_PIN_CHA PD2
#define ENC_PIN_CHB PD3

extern volatile int32_t enc_counter;

uint8_t read_ab();

void encoder_isr();

class Encoder : public Sensor<double> {
private:
  uint8_t cha_pin, chb_pin;
  void (*isr)();
  volatile int32_t& counter;
  double transformation;

  virtual double get_value() override;

public:
  Encoder(uint8_t cha_pin, uint8_t chb_pin, void (*isr)(), volatile int32_t& counter, double transformation = 1, uint32_t freq_hz = 0);

  void setup();
  virtual void reset();
};

#endif