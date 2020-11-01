#include "Leg.h"
#include "Joint.h"

Leg::Leg(void)
{
}

Leg::Leg(Direction direction, int elbowStepPin, int shoulderFlextionStepPin, int sholderAbductionStepPin)
{
    this->elbow = Joint(elbowStepPin, direction, 5, 100, 0, 0);
    this->shoulderFlextion = Joint(shoulderFlextionStepPin, direction, 5, 100, 0, 0);
    this->sholderAbduction = Joint(sholderAbductionStepPin, direction, 5, 100, 0, 0);
}

void Leg::startPosition()
{
    this->elbow.rotate(40);
    this->shoulderFlextion.rotate(150);
    this->sholderAbduction.rotate(90);
}

void Leg::stepForward()
{
    // this->elbow.rotate(10);
    // this->shoulderFlextion.rotate(130);
    // delay(200);
    // this->elbow.rotate(40);
    // this->shoulderFlextion.rotate(150);
}