#ifndef MY_Joint_H
#define MY_Joint_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN 150  // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN 400     // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX 2200    // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
 // Analog servos run at ~50 Hz updates


enum Direction
{
  DIRECTION_CW, // right joint
  DIRECTION_CCW // left joint
};

class Joint
{
private:
  int servoNo;
  Direction direction;
  int minAllowedAngle = 0;
  int maxAllowedAngle = 180;
  int tuneDiffAngle = 0;
  int leverageLength = 0;

public:    
  Joint();
  Joint(int servoNo, Direction direction, int minAllowedAngle, int maxAllowedAngle, int tuneDiffAngle, int leverageLength);
  static void setUp(int servoFreq);
  void rotate(int angle);
  void rotateTo(int baseAngle, int toAngle);
};

#endif