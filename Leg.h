#ifndef MY_LEG_H
#define MY_LEG_H

#include "Joint.h"

class Leg
{
private:
    int sf_init;
    int elbow_init_angle;
    int sholderAbduction_init_angle;
public:
    Leg();
    Leg(Direction direction, int elbowStepPin, int shoulderFlextionStepPin, int sholderAbductionStepPin);
    Joint elbow;
    Joint shoulderFlextion;
    Joint sholderAbduction;
    // void startPosition();
    // void stepForward();
    // void down();
    // void up();
    // void stepOrigin();
    // void stepUp();
    // void stepDown();
};

#endif