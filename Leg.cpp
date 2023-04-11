#include "Leg.h"
#include "Joint.h"

Leg::Leg(void)
{
}

Leg::Leg(Direction direction, int elbowStepPin, int shoulderFlextionStepPin, int sholderAbductionStepPin)
{
    this->sf_init = 165;
    this->elbow_init_angle = 90;
    this->sholderAbduction_init_angle = 90;
    this->elbow = Joint(elbowStepPin, direction, 1, 121, 0, 0);
    this->shoulderFlextion = Joint(shoulderFlextionStepPin, direction, 1, 120, 0, 0);
    this->sholderAbduction = Joint(sholderAbductionStepPin, direction, 29, 61, 0, 0);
}

// void Leg::startPosition()
// {
//     this->elbow.rotate(this->elbow_init_angle);
//     this->shoulderFlextion.rotate(this->sf_init);
//     this->sholderAbduction.rotate(this->sholderAbduction_init_angle);
// }

// void Leg::stepUp()
// {
//     this->shoulderFlextion.rotate(155);    
//     this->elbow.rotate(35);
// }

// void Leg::stepDown()
// {
//     this->shoulderFlextion.rotate(this->sf_init);    
//     this->elbow.rotate(40);
// }

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