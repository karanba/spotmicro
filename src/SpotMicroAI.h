#ifndef MY_SPOTMICROAI_H
#define MY_SPOTMICROAI_H

#include "Leg.h"

class SpotMicroAI
{
    private:
        Leg leftFrontLeg;
        Leg rightFrontLeg;

        Leg leftBackLeg;        
        Leg rightBackLeg;
    
    public:
        SpotMicroAI();
        void setUp(uint16_t pins[][3]);
        void startPosition();
};

#endif