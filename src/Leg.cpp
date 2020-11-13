#include "Leg.h"
#include "Joint.h"

Leg::Leg(void)
{
}

Leg::Leg(Direction direction, int elbowStepPin, int shoulderFlextionStepPin, int sholderAbductionStepPin)
{
    this->sf_init = 165;
    this->elbow = Joint(elbowStepPin, direction, 5, 100, 0, 0);
    this->shoulderFlextion = Joint(shoulderFlextionStepPin, direction, 5, 100, 0, 0);
    this->sholderAbduction = Joint(sholderAbductionStepPin, direction, 5, 100, 0, 0);
}

void Leg::startPosition()
{
    this->elbow.rotate(40);
    this->shoulderFlextion.rotate(this->sf_init);
    this->sholderAbduction.rotate(90);
}

void Leg::stepUp()
{
    this->shoulderFlextion.rotate(155);    
    this->elbow.rotate(35);
}

void Leg::stepDown()
{
    this->shoulderFlextion.rotate(this->sf_init);    
    this->elbow.rotate(40);
}

void Leg::stepForward()
{
    this->elbow.rotate(5);
    this->shoulderFlextion.rotate(110);    
    this->elbow.rotate(60);
}

void Leg::stepOrigin()
{    
    this->shoulderFlextion.rotate(this->sf_init);
    this->elbow.rotate(40);    
}

void Leg::pushUp()
{
    this->elbow.rotateTo(20,10);
    this->shoulderFlextion.rotateTo(140,150);   
}

void Leg::pushDown()
{
    this->elbow.rotateTo(10,20);
    this->shoulderFlextion.rotateTo(150,140);   
}