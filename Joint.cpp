#include "Joint.h"

Joint::Joint(void) {
}

Joint::Joint(int servoNo, Direction direction, int minAllowedAngle, int maxAllowedAngle, int tuneDiffAngle, int leverageLength) {
  this->servoNo = servoNo;
  this->direction = direction;
  this->minAllowedAngle = minAllowedAngle;
  this->maxAllowedAngle = maxAllowedAngle;
  this->tuneDiffAngle = tuneDiffAngle;
  this->leverageLength = leverageLength;
}

void Joint::rotate(Adafruit_PWMServoDriver pwm, int angle) {
  if (angle < this->minAllowedAngle || angle > this->maxAllowedAngle) {
    return;
  }
  Serial.println("rotate");
  Serial.println(angle);
  Serial.println(this->servoNo);
  // if (this->direction == DIRECTION_CCW) {
  //   angle = 180 - angle;
  // }

  uint16_t pulselength = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(this->servoNo, 0, pulselength);
  delay(10);
}

// void Joint::rotateSmooth(int toAngle) {
//   this->rotateTo(this->currentAngle, toAngle);
// }

// void Joint::rotateTo(int baseAngle, int toAngle) {
//   Serial.println("\nRotateTo(" + String(baseAngle) + ", " + String(toAngle) + ")");

//   if (baseAngle > toAngle) {
//     for (int angle = baseAngle; angle >= toAngle; angle--) {
//       this->rotate(angle);
//       delay(50);
//     }
//   }else{
//      for (int angle = baseAngle; angle <= toAngle; angle++) {
//       this->rotate(angle);
//       delay(50);
//     }
//   }


//   Serial.println("");
//   Serial.println("RotateTo done.");
// }