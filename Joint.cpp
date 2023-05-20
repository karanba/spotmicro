#include "Joint.h"

Joint::Joint() {
}

Joint::Joint(Adafruit_PWMServoDriver *Driver, int servoNo, Direction direction, int minAllowedAngle, int maxAllowedAngle, int tuneDiffAngle, int leverageLength, int fixAngle) {
  driver = Driver;
  this->servoNo = servoNo;
  this->direction = direction;
  this->minAllowedAngle = minAllowedAngle;
  this->maxAllowedAngle = maxAllowedAngle;
  this->tuneDiffAngle = tuneDiffAngle;
  this->leverageLength = leverageLength;
  this->fixAngle = fixAngle;
}

void Joint::rotate(int angle) {
  Serial.println("rotate angle");
  Serial.println(angle);
  Serial.println(this->servoNo);
  angle = angle - this->fixAngle;
  if (angle < this->minAllowedAngle || angle > this->maxAllowedAngle) {
    return;
  }
  this->currentAngle = angle;
  if (this->tuneDiffAngle > 0) {
    angle = 180 - angle - this->tuneDiffAngle;
  }
  uint16_t pulselength = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  driver->setPWM(this->servoNo, 0, pulselength);
  delay(5);
}

void Joint::rotateSmooth(int toAngle) {
  this->rotateTo(this->currentAngle, toAngle);
}

void Joint::rotateTo(int baseAngle, int toAngle) {
  Serial.println("\nRotateTo(" + String(baseAngle) + ", " + String(toAngle) + ")");

  if (baseAngle > toAngle) {
    for (int angle = baseAngle; angle >= toAngle; angle--) {
      this->rotate(angle);
      delay(40);
    }
  } else {
    for (int angle = baseAngle; angle <= toAngle; angle++) {
      this->rotate(angle);
      delay(40);
    }
  }


  Serial.println("");
  Serial.println("RotateTo done.");
}