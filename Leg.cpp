#include "Leg.h"

Leg ::Leg() {}

Leg::Leg(Adafruit_PWMServoDriver *Driver,
         Direction direction,
         int elbowStepPin, int shoulderFlextionStepPin, int sholderAbductionStepPin,
         int elbowFixAngle, int shoulderFixAngle, int abdFixAngle) {
  driver = Driver;

  this->sf_init = 165;
  this->elbow_init_angle = 90;
  this->sholderAbduction_init_angle = 90;

  int elbowTuneAngle = 0;
  if (direction == DIRECTION_CCW) {
    elbowTuneAngle = 90;
  }
  this->elbow = Joint(driver, elbowStepPin, direction, 1, 121, elbowTuneAngle, 0, elbowFixAngle);

  int soulderTuneAngle = 0;
  if (direction == DIRECTION_CCW) {
    soulderTuneAngle = 90;
  }
  this->shoulderFlextion = Joint(driver, shoulderFlextionStepPin, direction, 1, 120, soulderTuneAngle, 0, shoulderFixAngle);
  this->sholderAbduction = Joint(driver, sholderAbductionStepPin, direction, 39, 56, 0, 0, abdFixAngle);
}

// void Leg::startPosition()
// {
//     this->elbow.rotate(this->elbow_init_angle);
//     this->shoulderFlextion.rotate(this->sf_init);
//     this->sholderAbduction.rotate(this->sholderAbduction_init_angle);
// }

void Leg::stepA(int i) {
  this->shoulderFlextion.rotate(15 - i);
  this->elbow.rotate(60 + i);
}

void Leg::stepB(int i) {
  this->shoulderFlextion.rotate(i+5);
}

void Leg::stepC(int i) {
  this->elbow.rotate(70 - i);
}

void Leg::stepD(int i) {
  this->shoulderFlextion.rotate(15 - i);
}

// void Leg::down(){
//   this->shoulderFlextion.rotate(130);
// }

// void Leg::up(){
//   this->shoulderFlextion.rotate(150);
// }


// void Leg::stepForward()
// {
//     this->elbow.rotateSmooth(30);
//     delay(1000);
//     this->shoulderFlextion.rotateSmooth(130);
//     delay(1000);
//     this->elbow.rotateSmooth(60);
//     delay(1000);
//     this->shoulderFlextion.rotateSmooth(150);
//     delay(1000);
//     this->elbow.rotateSmooth(40);
//     delay(1000);
// }

// void Leg::stepOrigin()
// {
//     this->shoulderFlextion.rotateSmooth(165);
//     this->elbow.rotateSmooth(40);
// }