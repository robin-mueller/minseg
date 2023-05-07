// This file is automatically generated. Any changes will be overwritten.

#include "interface.hpp"

void ReceiveInterface::from_doc(StaticJsonDocument<JSON_DOC_SIZE_RX> &doc) {
JsonVariant var0 = doc["calibration"];
if (!var0.isNull()) this->calibration = var0.as<bool>();
JsonVariant var1 = doc["control_state"];
if (!var1.isNull()) this->control_state = var1.as<bool>();
JsonVariant var2 = doc["pos_setpoint_mm"];
if (!var2.isNull()) this->pos_setpoint_mm = var2.as<double>();
JsonVariant var3 = doc["reset_pos"];
if (!var3.isNull()) this->reset_pos = var3.as<bool>();
JsonVariant var4 = doc["parameters"]["variable"]["General"]["h_ms"];
if (!var4.isNull()) this->parameters.variable.General.h_ms = var4.as<uint16_t>();
JsonVariant var5 = doc["parameters"]["variable"]["General"]["alpha_off"];
if (!var5.isNull()) this->parameters.variable.General.alpha_off = var5.as<double>();
JsonVariant var6 = doc["parameters"]["variable"]["General"]["r_stop"];
if (!var6.isNull()) this->parameters.variable.General.r_stop = var6.as<uint8_t>();
JsonVariant var7 = doc["parameters"]["variable"]["General"]["r_start"];
if (!var7.isNull()) this->parameters.variable.General.r_start = var7.as<uint8_t>();
JsonVariant var9 = doc["parameters"]["variable"]["BalanceControl"]["k1"];
if (!var9.isNull()) this->parameters.variable.BalanceControl.k1 = var9.as<double>();
JsonVariant var10 = doc["parameters"]["variable"]["BalanceControl"]["k2"];
if (!var10.isNull()) this->parameters.variable.BalanceControl.k2 = var10.as<double>();
JsonVariant var11 = doc["parameters"]["variable"]["BalanceControl"]["k3"];
if (!var11.isNull()) this->parameters.variable.BalanceControl.k3 = var11.as<double>();
JsonVariant var12 = doc["parameters"]["variable"]["BalanceControl"]["k4"];
if (!var12.isNull()) this->parameters.variable.BalanceControl.k4 = var12.as<double>();
JsonVariant var14 = doc["parameters"]["variable"]["PositionControl"]["ki"];
if (!var14.isNull()) this->parameters.variable.PositionControl.ki = var14.as<double>();
JsonVariant var17 = doc["parameters"]["inferred"]["observer"]["gain"]["l11"];
if (!var17.isNull()) this->parameters.inferred.observer.gain.l11 = var17.as<double>();
JsonVariant var18 = doc["parameters"]["inferred"]["observer"]["gain"]["l12"];
if (!var18.isNull()) this->parameters.inferred.observer.gain.l12 = var18.as<double>();
JsonVariant var19 = doc["parameters"]["inferred"]["observer"]["gain"]["l13"];
if (!var19.isNull()) this->parameters.inferred.observer.gain.l13 = var19.as<double>();
JsonVariant var20 = doc["parameters"]["inferred"]["observer"]["gain"]["l21"];
if (!var20.isNull()) this->parameters.inferred.observer.gain.l21 = var20.as<double>();
JsonVariant var21 = doc["parameters"]["inferred"]["observer"]["gain"]["l22"];
if (!var21.isNull()) this->parameters.inferred.observer.gain.l22 = var21.as<double>();
JsonVariant var22 = doc["parameters"]["inferred"]["observer"]["gain"]["l23"];
if (!var22.isNull()) this->parameters.inferred.observer.gain.l23 = var22.as<double>();
JsonVariant var23 = doc["parameters"]["inferred"]["observer"]["gain"]["l31"];
if (!var23.isNull()) this->parameters.inferred.observer.gain.l31 = var23.as<double>();
JsonVariant var24 = doc["parameters"]["inferred"]["observer"]["gain"]["l32"];
if (!var24.isNull()) this->parameters.inferred.observer.gain.l32 = var24.as<double>();
JsonVariant var25 = doc["parameters"]["inferred"]["observer"]["gain"]["l33"];
if (!var25.isNull()) this->parameters.inferred.observer.gain.l33 = var25.as<double>();
JsonVariant var26 = doc["parameters"]["inferred"]["observer"]["gain"]["l41"];
if (!var26.isNull()) this->parameters.inferred.observer.gain.l41 = var26.as<double>();
JsonVariant var27 = doc["parameters"]["inferred"]["observer"]["gain"]["l42"];
if (!var27.isNull()) this->parameters.inferred.observer.gain.l42 = var27.as<double>();
JsonVariant var28 = doc["parameters"]["inferred"]["observer"]["gain"]["l43"];
if (!var28.isNull()) this->parameters.inferred.observer.gain.l43 = var28.as<double>();
JsonVariant var30 = doc["parameters"]["inferred"]["observer"]["phi"]["phi11"];
if (!var30.isNull()) this->parameters.inferred.observer.phi.phi11 = var30.as<double>();
JsonVariant var31 = doc["parameters"]["inferred"]["observer"]["phi"]["phi12"];
if (!var31.isNull()) this->parameters.inferred.observer.phi.phi12 = var31.as<double>();
JsonVariant var32 = doc["parameters"]["inferred"]["observer"]["phi"]["phi13"];
if (!var32.isNull()) this->parameters.inferred.observer.phi.phi13 = var32.as<double>();
JsonVariant var33 = doc["parameters"]["inferred"]["observer"]["phi"]["phi14"];
if (!var33.isNull()) this->parameters.inferred.observer.phi.phi14 = var33.as<double>();
JsonVariant var34 = doc["parameters"]["inferred"]["observer"]["phi"]["phi21"];
if (!var34.isNull()) this->parameters.inferred.observer.phi.phi21 = var34.as<double>();
JsonVariant var35 = doc["parameters"]["inferred"]["observer"]["phi"]["phi22"];
if (!var35.isNull()) this->parameters.inferred.observer.phi.phi22 = var35.as<double>();
JsonVariant var36 = doc["parameters"]["inferred"]["observer"]["phi"]["phi23"];
if (!var36.isNull()) this->parameters.inferred.observer.phi.phi23 = var36.as<double>();
JsonVariant var37 = doc["parameters"]["inferred"]["observer"]["phi"]["phi24"];
if (!var37.isNull()) this->parameters.inferred.observer.phi.phi24 = var37.as<double>();
JsonVariant var38 = doc["parameters"]["inferred"]["observer"]["phi"]["phi31"];
if (!var38.isNull()) this->parameters.inferred.observer.phi.phi31 = var38.as<double>();
JsonVariant var39 = doc["parameters"]["inferred"]["observer"]["phi"]["phi32"];
if (!var39.isNull()) this->parameters.inferred.observer.phi.phi32 = var39.as<double>();
JsonVariant var40 = doc["parameters"]["inferred"]["observer"]["phi"]["phi33"];
if (!var40.isNull()) this->parameters.inferred.observer.phi.phi33 = var40.as<double>();
JsonVariant var41 = doc["parameters"]["inferred"]["observer"]["phi"]["phi34"];
if (!var41.isNull()) this->parameters.inferred.observer.phi.phi34 = var41.as<double>();
JsonVariant var42 = doc["parameters"]["inferred"]["observer"]["phi"]["phi41"];
if (!var42.isNull()) this->parameters.inferred.observer.phi.phi41 = var42.as<double>();
JsonVariant var43 = doc["parameters"]["inferred"]["observer"]["phi"]["phi42"];
if (!var43.isNull()) this->parameters.inferred.observer.phi.phi42 = var43.as<double>();
JsonVariant var44 = doc["parameters"]["inferred"]["observer"]["phi"]["phi43"];
if (!var44.isNull()) this->parameters.inferred.observer.phi.phi43 = var44.as<double>();
JsonVariant var45 = doc["parameters"]["inferred"]["observer"]["phi"]["phi44"];
if (!var45.isNull()) this->parameters.inferred.observer.phi.phi44 = var45.as<double>();
JsonVariant var47 = doc["parameters"]["inferred"]["observer"]["innoGain"]["mx11"];
if (!var47.isNull()) this->parameters.inferred.observer.innoGain.mx11 = var47.as<double>();
JsonVariant var48 = doc["parameters"]["inferred"]["observer"]["innoGain"]["mx12"];
if (!var48.isNull()) this->parameters.inferred.observer.innoGain.mx12 = var48.as<double>();
JsonVariant var49 = doc["parameters"]["inferred"]["observer"]["innoGain"]["mx13"];
if (!var49.isNull()) this->parameters.inferred.observer.innoGain.mx13 = var49.as<double>();
JsonVariant var50 = doc["parameters"]["inferred"]["observer"]["innoGain"]["mx21"];
if (!var50.isNull()) this->parameters.inferred.observer.innoGain.mx21 = var50.as<double>();
JsonVariant var51 = doc["parameters"]["inferred"]["observer"]["innoGain"]["mx22"];
if (!var51.isNull()) this->parameters.inferred.observer.innoGain.mx22 = var51.as<double>();
JsonVariant var52 = doc["parameters"]["inferred"]["observer"]["innoGain"]["mx23"];
if (!var52.isNull()) this->parameters.inferred.observer.innoGain.mx23 = var52.as<double>();
JsonVariant var53 = doc["parameters"]["inferred"]["observer"]["innoGain"]["mx31"];
if (!var53.isNull()) this->parameters.inferred.observer.innoGain.mx31 = var53.as<double>();
JsonVariant var54 = doc["parameters"]["inferred"]["observer"]["innoGain"]["mx32"];
if (!var54.isNull()) this->parameters.inferred.observer.innoGain.mx32 = var54.as<double>();
JsonVariant var55 = doc["parameters"]["inferred"]["observer"]["innoGain"]["mx33"];
if (!var55.isNull()) this->parameters.inferred.observer.innoGain.mx33 = var55.as<double>();
JsonVariant var56 = doc["parameters"]["inferred"]["observer"]["innoGain"]["mx41"];
if (!var56.isNull()) this->parameters.inferred.observer.innoGain.mx41 = var56.as<double>();
JsonVariant var57 = doc["parameters"]["inferred"]["observer"]["innoGain"]["mx42"];
if (!var57.isNull()) this->parameters.inferred.observer.innoGain.mx42 = var57.as<double>();
JsonVariant var58 = doc["parameters"]["inferred"]["observer"]["innoGain"]["mx43"];
if (!var58.isNull()) this->parameters.inferred.observer.innoGain.mx43 = var58.as<double>();
}

StaticJsonDocument<JSON_DOC_SIZE_TX> TransmitInterface::to_doc() {
StaticJsonDocument<JSON_DOC_SIZE_TX> doc;
JsonObject obj0 = doc.createNestedObject("sensor");
JsonObject obj1 = obj0.createNestedObject("wheel");
obj1["angle_rad"] = this->sensor.wheel.angle_rad;
obj1["angle_deriv_rad_s"] = this->sensor.wheel.angle_deriv_rad_s;
JsonObject obj2 = obj0.createNestedObject("tilt");
obj2["angle_rad"] = this->sensor.tilt.angle_rad;
obj2["vel_rad_s"] = this->sensor.tilt.vel_rad_s;
JsonObject obj3 = doc.createNestedObject("observer");
JsonObject obj4 = obj3.createNestedObject("wheel");
obj4["angle_rad"] = this->observer.wheel.angle_rad;
obj4["vel_rad_s"] = this->observer.wheel.vel_rad_s;
JsonObject obj5 = obj3.createNestedObject("tilt");
obj5["angle_rad"] = this->observer.tilt.angle_rad;
obj5["vel_rad_s"] = this->observer.tilt.vel_rad_s;
JsonObject obj6 = obj3.createNestedObject("position");
obj6["s_mm"] = this->observer.position.s_mm;
obj6["xs"] = this->observer.position.xs;
JsonObject obj7 = doc.createNestedObject("control");
obj7["cycle_us"] = this->control.cycle_us;
obj7["u"] = this->control.u;
obj7["motor"] = this->control.motor;
doc["calibrated"] = this->calibrated;

return doc;
}
