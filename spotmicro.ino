#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "SpotMicroAI.h"

#define SERVO_FREQ 50

const int LEFT_FRONT_W = 0;
const int RIGHT_FRONT_W = 1;
const int LEFT_BACK_W = 2;
const int RIGHT_BACK_W = 3;

const int LEFT_FRONT_F = 4;
const int RIGHT_FRONT_F = 5;
const int LEFT_BACK_F = 6;
const int RIGHT_BACK_F = 7;

const int LEFT_FRONT_A = 8;
const int RIGHT_FRONT_A = 9;
const int LEFT_BACK_A = 10;
const int RIGHT_BACK_A = 11;

uint16_t spotPins[4][3] = {
  { LEFT_FRONT_W, LEFT_FRONT_F, LEFT_FRONT_A },
  { RIGHT_FRONT_W, RIGHT_FRONT_F, RIGHT_FRONT_A },
  { LEFT_BACK_W, LEFT_BACK_F, LEFT_BACK_A },
  { RIGHT_BACK_W, RIGHT_BACK_F, RIGHT_BACK_A }
};

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
SpotMicroAI spotMicroAI = SpotMicroAI();

void setup() {
  Serial.begin(9600);

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);

  delay(10);
  spotMicroAI.setUp(spotPins);
  //spotMicroAI.startPosition();

  //spotMicroAI.rightFrontLeg.elbow.rotate(pwm, 30);
  spotMicroAI.rightBackLeg.elbow.rotate(pwm, 30);

  //spotMicroAI.rightFrontLeg.shoulderFlextion.rotate(pwm, 10);
  spotMicroAI.rightBackLeg.shoulderFlextion.rotate(pwm, 2);


  //spotMicroAI.rightFrontLeg.sholderAbduction.rotate(pwm, 45);
  spotMicroAI.rightBackLeg.sholderAbduction.rotate(pwm, 45);
}

void loop() {
  spotMicroAI.rightBackLeg.elbow.rotate(pwm, 90);
  delay(1000);
  for (int i = 2; i <= 10; i++) {
    spotMicroAI.rightBackLeg.shoulderFlextion.rotate(pwm, i);
    delay(100);
  }
  spotMicroAI.rightBackLeg.elbow.rotate(pwm, 60);
  delay(1000);
  for (int i = 10; i >= 2; i--) {
    spotMicroAI.rightBackLeg.shoulderFlextion.rotate(pwm, i);
    delay(100);
  }
  delay(1000);

  //for (int i = 20; i < 30; i++) {
  //   spotMicroAI.rightFrontLeg.elbow.rotate(pwm, i);
  //   delay(500);
  // }
}