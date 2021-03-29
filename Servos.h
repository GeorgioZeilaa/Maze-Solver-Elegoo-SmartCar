/*
  Servos.h - Library for controlling the servo.
*/
#ifndef Servos_h
#define Servos_h

//default libraries used for the hardwares
#include <Servo.h>
#include <Arduino.h>

class Servos
{ 
  private:
  Servo myServo;
  
  public:
  void write(int angle);
  void attach();
};

#endif
