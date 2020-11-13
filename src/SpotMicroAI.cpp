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

void SpotMicroAI::pushUp()
{
    this->rightBackLeg.pushDown();
    this->leftBackLeg.pushDown();
    this->leftFrontLeg.pushDown();
    this->rightFrontLeg.pushDown();
    delay(1000);

    this->leftBackLeg.pushUp();
    this->rightBackLeg.pushUp();
    this->rightFrontLeg.pushUp();
    this->leftFrontLeg.pushUp();
    delay(1000);
}

void SpotMicroAI::walk()
{

    this->rightBackLeg.stepForward();
    this->leftBackLeg.stepOrigin();
    this->leftFrontLeg.stepForward();
    this->rightFrontLeg.stepOrigin();
    delay(1000);

    this->rightBackLeg.stepOrigin();
    this->leftBackLeg.stepForward();
    this->leftFrontLeg.stepOrigin();
    this->rightFrontLeg.stepForward();
    delay(1000);
}

void SpotMicroAI::march()
{
    int smootyTime = 50; // msec
    for (int demo1 = 0; demo1 < 3; demo1++)
    {
        for (int i = 0; i < 30; i++)
        {
            this->leftFrontLeg.elbow.rotate(i + 5);
            this->leftFrontLeg.shoulderFlextion.rotate(165 - i);

            this->rightFrontLeg.elbow.rotate(i + 5);
            this->rightFrontLeg.shoulderFlextion.rotate(165 - i);

            this->leftBackLeg.elbow.rotate(i + 5);
            this->leftBackLeg.shoulderFlextion.rotate(165 - i);

            this->rightBackLeg.elbow.rotate(i + 5);
            this->rightBackLeg.shoulderFlextion.rotate(165 - i);
            delay(smootyTime);
        }

        for (int i = 30; i > 0; i--)
        {
            this->leftFrontLeg.elbow.rotate(i + 5);
            this->leftFrontLeg.shoulderFlextion.rotate(165 - i);

            this->rightFrontLeg.elbow.rotate(i + 5);
            this->rightFrontLeg.shoulderFlextion.rotate(165 - i);

            this->leftBackLeg.elbow.rotate(i + 5);
            this->leftBackLeg.shoulderFlextion.rotate(165 - i);

            this->rightBackLeg.elbow.rotate(i + 5);
            this->rightBackLeg.shoulderFlextion.rotate(165 - i);
            delay(smootyTime);
        }

        for (int demo2 = 0; demo2 < 2; demo2++)
        {
            for (int omuz = 0; omuz < 10; omuz++)
            {
                this->leftBackLeg.sholderAbduction.rotate(90 + omuz);
                this->rightBackLeg.sholderAbduction.rotate(90 - omuz);
                this->leftFrontLeg.sholderAbduction.rotate(90 + omuz);
                this->rightFrontLeg.sholderAbduction.rotate(90 - omuz);
                delay(smootyTime);
            }

            for (int omuz = 10; omuz > 0; omuz--)
            {
                this->leftBackLeg.sholderAbduction.rotate(90 + omuz);
                this->rightBackLeg.sholderAbduction.rotate(90 - omuz);
                this->leftFrontLeg.sholderAbduction.rotate(90 + omuz);
                this->rightFrontLeg.sholderAbduction.rotate(90 - omuz);
                delay(smootyTime);
            }
        }
    }
}