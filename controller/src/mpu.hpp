#include "Arduino.h"
#ifndef MPU_HPP
#define MPU_HPP

#include "sensor.hpp"
#include <MPU9250.h>

class MPUMeasurement : public Sensor {
  MPU9250 *mpu;
  float (*getter)(MPU9250 *);

public:
  MPUMeasurement(MPU9250 *mpu, float (*getter)(MPU9250 *), uint32_t freq_hz = 0);

  double get_value() override;
};

class MinSegMPU : public MPU9250 {
public:
  MPUMeasurement tilt_angle_from_euler_rad;
  MPUMeasurement tilt_angle_from_acc_rad;
  MPUMeasurement tilt_vel_rad_s;

  MinSegMPU();

  void setup();
  bool update();
};

#endif
