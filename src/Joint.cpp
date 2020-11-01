#include "Joint.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void Joint::setUp(int servoFreq)
{
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(servoFreq);
}

Joint::Joint(void)
{
}

Joint::Joint(int servoNo, Direction direction, int minAllowedAngle, int maxAllowedAngle, int tuneDiffAngle, int leverageLength)
{
    this->servoNo = servoNo;
    this->direction = direction;
    this->minAllowedAngle = minAllowedAngle;
    this->maxAllowedAngle = maxAllowedAngle;
    this->tuneDiffAngle = tuneDiffAngle;
    this->leverageLength = leverageLength;
}

void Joint::rotate(int angle)
{
    if (this->direction == DIRECTION_CW)
    {
        angle = 180 - angle;
    }
    uint16_t pulselength = map(angle, 0, 180, USMIN, USMAX);
    pwm.writeMicroseconds(this->servoNo, pulselength);
}

void Joint::rotateTo(int baseAngle, int toAngle)
{
    if (baseAngle < toAngle)
    {
        for (int angle = baseAngle; angle < toAngle; angle++)
        {
            this->rotate(angle);
        }
    }
    else
    {
        for (int angle = toAngle; angle < baseAngle; angle++)
        {
            this->rotate(angle);
        }
    }
}