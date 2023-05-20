#ifndef MY_LEG_H
#define MY_LEG_H

#include "Joint.h"

class Leg {
private:
  Adafruit_PWMServoDriver *driver;
  int sf_init;
  int elbow_init_angle;
  int sholderAbduction_init_angle;
public:
  Leg();
  Leg(Adafruit_PWMServoDriver *Driver, Direction direction, int elbowStepPin, int shoulderFlextionStepPin, int sholderAbductionStepPin, int elbowFixAngle, int shoulderFixAngle, int abdFixAngle);
  Joint elbow;
  Joint shoulderFlextion;
  Joint sholderAbduction;
  // void startPosition();
  // void stepForward();
  // void down();
  // void up();
  // void stepOrigin();
  void stepA(int i);
  void stepB(int i);
  void stepC(int i);
  void stepD(int i);
};

#endif