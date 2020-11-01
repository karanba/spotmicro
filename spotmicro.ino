#include <Arduino.h>
#include "src/SpotMicroAI.h"

#define SERVO_FREQ 50

const int LEFT_FRONT_W = 0;
const int RIGHT_FRONT_W = 1;
const int LEFT_BACK_W = 2;
const int RIGHT_BACK_W = 3;

const int LEFT_FRONT_F = 4;
const int RIGHT_FRONT_F = 5;
const int LEFT_BACK_F = 6;
const int RIGHT_BACK_F = 7;

const int LEFT_FRONT_A = 8;
const int RIGHT_FRONT_A = 9;
const int LEFT_BACK_A = 10;
const int RIGHT_BACK_A = 11;

uint16_t spotPins[4][3] = {
    {LEFT_FRONT_W, LEFT_FRONT_F, LEFT_FRONT_A},
    {RIGHT_FRONT_W, RIGHT_FRONT_F, RIGHT_FRONT_A},
    {LEFT_BACK_W, LEFT_BACK_F, LEFT_BACK_A},
    {RIGHT_BACK_W, RIGHT_BACK_F, RIGHT_BACK_A}};

SpotMicroAI spotMicroAI = SpotMicroAI();

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  Joint::setUp(SERVO_FREQ);
  delay(10);
  spotMicroAI.setUp(spotPins);
  spotMicroAI.startPosition();
}

void loop()
{  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}