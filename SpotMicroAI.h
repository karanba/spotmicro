#ifndef MY_SPOTMICROAI_H
#define MY_SPOTMICROAI_H

#include "Leg.h"

class SpotMicroAI {
private:


public:
  Leg leftFrontLeg;
  Leg rightFrontLeg;

  Leg leftBackLeg;
  Leg rightBackLeg;
  SpotMicroAI();
  void setUp(uint16_t pins[][3]);
  //   void startPosition();
  //   void walk();
  //   void march();
};

#endif