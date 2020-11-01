#ifndef MY_LEG_H
#define MY_LEG_H

#include "Joint.h"

class Leg
{
private:
    Joint elbow;
    Joint shoulderFlextion;
    Joint sholderAbduction;

public:
    Leg();
    Leg(Direction direction, int elbowStepPin, int shoulderFlextionStepPin, int sholderAbductionStepPin);
    void startPosition();
    void stepForward();
};

#endif