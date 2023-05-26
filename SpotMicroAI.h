#ifndef MY_SPOTMICROAI_H
#define MY_SPOTMICROAI_H

#define SERVO_FREQ 50
#define Oscillator_Frequency 27000000

#include "Leg.h"

// pins 

#define LEFT_FRONT_ELBOW_PIN 0
#define RIGHT_FRONT_ELBOW_PIN 1
#define LEFT_BACK_ELBOW_PIN 2
#define RIGHT_BACK_ELBOW_PIN 3

#define LEFT_FRONT_SHOULDER_PIN 4
#define RIGHT_FRONT_SHOULDER_PIN 5
#define LEFT_BACK_SHOULDER_PIN 6
#define RIGHT_BACK_SHOULDER_PIN 7

#define LEFT_FRONT_A_PIN 8
#define RIGHT_FRONT_A_PIN 9
#define LEFT_BACK_A_PIN 10
#define RIGHT_BACK_A_PIN 11

// fix angles

#define LEFT_FRONT_ELBOW_FA 0 
#define RIGHT_FRONT_ELBOW_FA 0
#define LEFT_BACK_ELBOW_FA 0
#define RIGHT_BACK_ELBOW_FA 0

#define LEFT_FRONT_SHOULDER_FA 0
#define RIGHT_FRONT_SHOULDER_FA 0
#define LEFT_BACK_SHOULDER_FA 10
#define RIGHT_BACK_SHOULDER_FA 0

#define LEFT_FRONT_A_FA 0
#define RIGHT_FRONT_A_FA -2
#define LEFT_BACK_A_FA 0
#define RIGHT_BACK_A_FA 5




class SpotMicroAI {
private:
  Adafruit_PWMServoDriver *driver;  //reference to driver instantiation

public:
  Leg leftFrontLeg;
  Leg rightFrontLeg;

  Leg leftBackLeg;
  Leg rightBackLeg;
  SpotMicroAI(Adafruit_PWMServoDriver *pwm);
  void setUp();
  void startPosition();
  //   void walk();
  //   void march();
};

#endif