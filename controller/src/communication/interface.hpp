// This file is automatically generated. Any changes will be overwritten.

#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <ArduinoJson.h>

#define JSON_DOC_SIZE_RX 63
#define JSON_DOC_SIZE_TX 96

struct ReceiveInterface {
bool calibration;
bool control_state;
double pos_setpoint;

void from_doc(StaticJsonDocument<JSON_DOC_SIZE_RX> &doc);
};

struct TransmitInterface {
struct {
double pos_rad;
double pos_deriv_rad_s;
} wheel;
struct {
struct {
double from_euler;
double from_acc;
} angle_deg;
struct {
double from_euler;
double from_acc;
} angle_deriv_deg_s;
double vel_deg_s;
} tilt;
bool calibrated;

StaticJsonDocument<JSON_DOC_SIZE_TX> to_doc();
};

#endif
