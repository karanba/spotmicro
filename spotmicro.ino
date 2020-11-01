#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  400 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2200 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

int altsinir = 0;
int ustsinir = 180;

int aci = 40;

const int sol_on_D = 0;
const int sag_on_D = 1;
const int sol_arka_D = 2;
const int sag_arka_D = 3;

const int sol_on_K = 4;
const int sag_on_K = 5;
const int sol_arka_K = 6;
const int sag_arka_K = 7;


const int sol_on_OM = 8;
const int sag_on_OM = 9;
const int sol_arka_OM = 10;
const int sag_arka_OM = 11;

class Servo
{
  private:
    int servoNo;

  public:
    Servo(int servoNo);
    void turnTo(int angle);
    void turnSmooth(int fromAngle, into Angle);
}
t
Servo::Servo(int servoNo)
{
  this->servoNo = servoNo;
}

Servo::turnTo(int angle)
{
  if (this->servoNo % 2 == 1) {
    // saglar için
    angle = 180 - angle;
  }
  uint16_t pulselength = map(angle, 0, 180, USMIN, USMAX);
  pwm.writeMicroseconds(this->servoNo, pulselength);
}

Servo::turnSmooth(int fromAngle, int toAngle)
{
  if (fromAngle < toAngle) {
    for (int angle = fromAngle; angle < toAngle; i++)
    {
      this->turnTo(angle);
    }
  }
  else
  {
    for (int angle = toAngle; angle < fromAngle; i++)
    {
      this->turnTo(angle);
    }
  }
}





// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
}

void loop() { 
  baslangic();
  delay(1000);
}

void goto_angel(int degree, int servo_number)
{
  if (servo_number % 2 == 1) {
    degree = 180 - degree;
  }
  uint16_t pulselength = map(degree, 0, 180, USMIN, USMAX);

  pwm.writeMicroseconds(servo_number, pulselength);
}

void goto_between_angels(int degreeFrom, int degreeTo, int servo_number)
{
  if (degreeTo >= degreeFrom) {
    for (int i = degreeFrom; i < degreeTo; i++) {
      goto_angel(i, servo_number);
      delay(25);
    }
  } else {
    for (int i = degreeFrom; i > degreeTo; i--) {
      goto_angel(i, servo_number);
      delay(25);
    }
  }
}

void baslangic()
{
  int i;
  int del = 100;
  // dirsek
  for (int degree = 1; degree < 15; degree++) {
    for (int servoNum = 0; servoNum < 4; servoNum++)
    {
      goto_angel(60 - degree * 3, servoNum);
      delay(del);
    }

    for (int servoNum = 4; servoNum < 8; servoNum++)
    {
      goto_angel(160 + degree, servoNum); // dirsekler hepsi  10 derecede
      delay(del);
    }
  }


  for (int degree = 10; degree > 0; degree--) {
    for (int servoNum = 0; servoNum < 4; servoNum++)
    {
      goto_angel(60 - degree * 3, servoNum);
      delay(del);
    }

    for (int servoNum = 4; servoNum < 8; servoNum++)
    {
      goto_angel(160 + degree, servoNum); // dirsekler hepsi  10 derecede
      delay(del);
    }
  }

  // Omuzları 90 a ayarlıyoz
  for (i = 8; i < 12; i = i + 1)
  {
    goto_angel(90, i); // dirsekler hepsi  10 derecede
  }
}
