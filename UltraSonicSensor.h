/*
  UltraSonicSensor.h - Library for controlling the Ultra-Sonic Sensor.
*/
#ifndef UltraSonicSensor_h
#define UltraSonicSensor_h

//default library used for the hardware
#include <Arduino.h>

//library used to control the servo
#include "Servos.h"

class UltraSonicSensor
{
  private:
  //initializing object for the use of servo
  Servos myServos;
  
  //for ultra-sonic sensor
  int Echo = A4;//receiver
  int Trig = A5;//transmitter
  
  public:
  void attachServo();//to configure servo with the correct pin value
  int measureDistance();//returns distance from object
  void scanDistance(int angle);//to rotate the servo

  //to scan with different directions and return the distance to obstacle
  int scanRight();
  int scanLeft();
  int scanMiddle();
};

#endif
