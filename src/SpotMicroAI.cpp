#include "SpotMicroAI.h"

SpotMicroAI::SpotMicroAI()
{
}

void SpotMicroAI::setUp(uint16_t pins[][3])
{
    this->leftFrontLeg = Leg(DIRECTION_CCW,
                             pins[0][0],
                             pins[0][1],
                             pins[0][2]);

    this->rightFrontLeg = Leg(DIRECTION_CW,
                              pins[1][0],
                              pins[1][1],
                              pins[1][2]);

    this->leftBackLeg = Leg(DIRECTION_CCW,
                            pins[2][0],
                            pins[2][1],
                            pins[2][2]);

    this->rightBackLeg = Leg(DIRECTION_CW,
                             pins[3][0],
                             pins[3][1],
                             pins[3][2]);
}

void SpotMicroAI::startPosition()
{
    this->leftFrontLeg.startPosition();
    this->rightFrontLeg.startPosition();
    this->leftBackLeg.startPosition();
    this->rightBackLeg.startPosition();
}