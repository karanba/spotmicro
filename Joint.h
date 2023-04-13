#ifndef MY_Joint_H
#define MY_Joint_H
#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN 150  // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN 400     // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX 2200    // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600

enum Direction {
  DIRECTION_CW,  // right joint
  DIRECTION_CCW  // left joint
};

class Joint {
private:
  Adafruit_PWMServoDriver *driver;
  int servoNo;
  Direction direction;
  int minAllowedAngle = 0;
  int maxAllowedAngle = 180;
  int tuneDiffAngle = 0;
  int leverageLength = 0;
  int currentAngle = 0;

public:
  Joint();
  Joint(Adafruit_PWMServoDriver *Driver, int servoNo, Direction direction, int minAllowedAngle, int maxAllowedAngle, int tuneDiffAngle, int leverageLength);
  void rotate(int angle);
  void rotateTo(int baseAngle, int toAngle);
  void rotateSmooth(int toAngle);
};

#endif