#include "SpotMicroAI.h"

SpotMicroAI::SpotMicroAI(Adafruit_PWMServoDriver *pwm) {
  driver = pwm;
}

void SpotMicroAI::setUp() {
  driver->begin();
  driver->setOscillatorFrequency(Oscillator_Frequency);
  driver->setPWMFreq(SERVO_FREQ);

  delay(10);
  this->leftFrontLeg = Leg(driver,
                           DIRECTION_CCW,
                           LEFT_FRONT_ELBOW_PIN,
                           LEFT_FRONT_SHOULDER_PIN,
                           LEFT_FRONT_A_PIN);

  this->rightFrontLeg = Leg(driver,
                            DIRECTION_CW,
                            RIGHT_FRONT_ELBOW_PIN,
                            RIGHT_FRONT_SHOULDER_PIN,
                            RIGHT_FRONT_A_PIN);

  this->leftBackLeg = Leg(driver,
                          DIRECTION_CCW,
                          LEFT_BACK_ELBOW_PIN,
                          LEFT_BACK_SHOULDER_PIN,
                          LEFT_BACK_A_PIN);

  this->rightBackLeg = Leg(driver,
                           DIRECTION_CW,
                           RIGHT_BACK_ELBOW_PIN,
                           RIGHT_BACK_SHOULDER_PIN,
                           RIGHT_BACK_A_PIN);
}

void SpotMicroAI::startPosition() {
  int elbow = 60;
  int shoulder = 10;
  int abduction = 45;


  this->leftBackLeg.sholderAbduction.rotate(abduction);
  this->rightBackLeg.sholderAbduction.rotate(abduction);
  this->leftFrontLeg.sholderAbduction.rotate(abduction);
  this->rightFrontLeg.sholderAbduction.rotate(abduction);

  this->leftFrontLeg.elbow.rotate(elbow);
  this->rightFrontLeg.elbow.rotate(elbow);
  this->leftBackLeg.elbow.rotate(elbow);
  this->rightBackLeg.elbow.rotate(elbow);

   this->leftBackLeg.shoulderFlextion.rotate(shoulder);
   this->rightBackLeg.shoulderFlextion.rotate(shoulder);
   this->leftFrontLeg.shoulderFlextion.rotate(shoulder);
   this->rightFrontLeg.shoulderFlextion.rotate(shoulder);


  // this->leftFrontLeg.startPosition();
  // this->rightFrontLeg.startPosition();
  // this->leftBackLeg.startPosition();
  // this->rightBackLeg.startPosition();
}

// void SpotMicroAI::walk()
// {

//     //this->rightBackLeg.stepForward();
//     // this->leftBackLeg.stepOrigin();
//     // this->leftFrontLeg.stepOrigin();
//     this->rightFrontLeg.down();


//     // this->leftBackLeg.stepForward();
//     // this->rightBackLeg.stepOrigin();
//     // this->rightFrontLeg.stepOrigin();
//     // this->leftFrontLeg.stepForward();
//     this->rightFrontLeg.up();
//     // delay(1000);
// }

// void SpotMicroAI::march()
// {
//     this->rightFrontLeg.stepUp();
//     this->leftBackLeg.stepUp();
//     delay(500);
//     this->rightFrontLeg.stepDown();
//     this->leftBackLeg.stepDown();
//     delay(500);
//     this->leftFrontLeg.stepUp();
//     this->rightBackLeg.stepUp();
//     delay(500);
//     this->leftFrontLeg.stepDown();
//     this->rightBackLeg.stepDown();
// }