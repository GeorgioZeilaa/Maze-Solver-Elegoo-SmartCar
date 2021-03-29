#include "UltraSonicSensor.h"

void UltraSonicSensor::attachServo()
{
  myServos.attach();
}

int UltraSonicSensor::measureDistance()//to measure the distance that is done by ultra-sonic sensor
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);//to enable the transmitter for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float Fdistance = pulseIn(Echo, HIGH);//returns the sound wave travel time in microseconds
  Fdistance= Fdistance*0.034/2;
  return (int)Fdistance;
}

void UltraSonicSensor::scanDistance(int angle)
{
  myServos.write(angle);//to rotate the servo that has ultra-sonic sensor on it
}

int UltraSonicSensor::scanMiddle()
{
  scanDistance(90);//the set the angle of the servo to the middle
  return measureDistance();
}

int UltraSonicSensor::scanLeft()
{
  scanDistance(180);//the set the angle of the servo to the left
  return measureDistance();
}

int UltraSonicSensor::scanRight()
{
  scanDistance(0);//the set the angle of the servo to the right
  return measureDistance();
}
