#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>
#include "SpotMicroAI.h"


Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver();
SpotMicroAI spotMicroAI = SpotMicroAI(&driver);
char input;
//SoftwareSerial BTSerial(18, 19);  // RX, TX

void setup() {
  Serial.begin(9600);
  spotMicroAI.setUp();
  spotMicroAI.startPosition();
}

void loop() {

  // int j = 0;
  // for (int i = 0; i <= 60; i++) {

  //   if (i < 30) {
  //     j = i;
  //   } else {
  //     j = 60 - i;
  //   }

  //   spotMicroAI.leftFrontLeg.elbow.rotate(60 + j);
  //   spotMicroAI.rightFrontLeg.elbow.rotate(60 + j);

  //    spotMicroAI.leftFrontLeg.shoulderFlextion.rotate(5 + j);
  //    spotMicroAI.rightFrontLeg.shoulderFlextion.rotate(5 + j);

  //   spotMicroAI.leftBackLeg.elbow.rotate(60 +  j / 2);
  //   spotMicroAI.rightBackLeg.elbow.rotate(60 + j / 2);

    
  // }




  for (int i = 10; i > 0; i--) {

    spotMicroAI.leftFrontLeg.elbow.rotate(70 - i);
    spotMicroAI.rightFrontLeg.elbow.rotate(70 - i);

    spotMicroAI.leftBackLeg.elbow.rotate(70 - i);
    spotMicroAI.rightBackLeg.elbow.rotate(70 - i);

    delay(50);
  }

  for (int i = 1; i <= 10; i++) {
    spotMicroAI.leftFrontLeg.stepA(i);
    spotMicroAI.rightBackLeg.stepA(i);
    spotMicroAI.leftBackLeg.stepC(i);
    spotMicroAI.rightFrontLeg.stepC(i);
  }

  for (int i = 1; i <= 10; i++) {
    spotMicroAI.leftFrontLeg.stepB(i);
    spotMicroAI.rightBackLeg.stepB(i);
    spotMicroAI.leftBackLeg.stepA(i);
    spotMicroAI.rightFrontLeg.stepA(i);
  }

  for (int i = 1; i <= 10; i++) {

    spotMicroAI.rightFrontLeg.stepB(i);
  }

  for (int i = 1; i <= 10; i++) {
    spotMicroAI.leftFrontLeg.stepD(i);
    spotMicroAI.rightBackLeg.stepD(i);
  }


  // for (int i = 0; i <= 10; i++) {
  //   spotMicroAI.rightBackLeg.elbow.rotate(80-i);
  //   spotMicroAI.rightBackLeg.shoulderFlextion.rotate(i);

  //   spotMicroAI.leftBackLeg.elbow.rotate(80-i);
  //   spotMicroAI.leftBackLeg.shoulderFlextion.rotate(i);

  //   spotMicroAI.rightFrontLeg.elbow.rotate(80-i);
  //   spotMicroAI.rightFrontLeg.shoulderFlextion.rotate(i);

  //   spotMicroAI.leftFrontLeg.elbow.rotate(80-i);
  //   spotMicroAI.leftFrontLeg.shoulderFlextion.rotate(i);

  //   delay(100);
  // }

  // for (int i = 10; i >= 0; i--) {
  //   // spotMicroAI.rightBackLeg.elbow.rotate(80 - i);
  //   // spotMicroAI.rightBackLeg.shoulderFlextion.rotate(i);

  //   // spotMicroAI.leftBackLeg.elbow.rotate(80 - i);
  //   // spotMicroAI.leftBackLeg.shoulderFlextion.rotate(i);

  //   // spotMicroAI.rightFrontLeg.elbow.rotate(80 - i);
  //   // spotMicroAI.rightFrontLeg.shoulderFlextion.rotate(i);

  //   spotMicroAI.leftFrontLeg.elbow.rotate(80 - i);
  //   spotMicroAI.leftFrontLeg.shoulderFlextion.rotate(i);

  //   delay(100);
  // }

  // for (int i = 0; i < 40; i++) {
  //   spotMicroAI.leftFrontLeg.shoulderFlextion.rotate(i);
  //   spotMicroAI.leftBackLeg.shoulderFlextion.rotate(i);

  //   spotMicroAI.rightBackLeg.shoulderFlextion.rotate(i);
  //   spotMicroAI.rightFrontLeg.shoulderFlextion.rotate(i);
  //   delay(40);
  // }

  // for (int i = 40; i > 0; i--) {
  //   spotMicroAI.leftFrontLeg.shoulderFlextion.rotate(i);
  //   spotMicroAI.leftBackLeg.shoulderFlextion.rotate(i);

  //   spotMicroAI.rightBackLeg.shoulderFlextion.rotate(i);
  //   spotMicroAI.rightFrontLeg.shoulderFlextion.rotate(i);
  //   delay(40);
  // }

  // spotMicroAI.rightBackLeg.elbow.rotate(90);
  // spotMicroAI.rightFrontLeg.elbow.rotate(90);
  // delay(1000);

  // for (int i = 2; i <= 10; i++) {
  //   spotMicroAI.rightBackLeg.shoulderFlextion.rotate(i);
  //   spotMicroAI.rightBackLeg.elbow.rotate(90 + i);

  //   spotMicroAI.rightFrontLeg.shoulderFlextion.rotate(i);
  //   spotMicroAI.rightFrontLeg.elbow.rotate(90 + i);

  //   delay(50);
  // }


  // for (int i = 10; i >= 2; i--) {
  //   spotMicroAI.rightBackLeg.shoulderFlextion.rotate(i);
  //   spotMicroAI.rightBackLeg.elbow.rotate(90 + i);

  //   spotMicroAI.rightFrontLeg.shoulderFlextion.rotate(i);
  //   spotMicroAI.rightFrontLeg.elbow.rotate(90 + i);
  //   delay(50);
  // }
}