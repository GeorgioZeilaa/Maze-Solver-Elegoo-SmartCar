/*
  Movement.h - Library for moving the robot in certain direction.
*/
#ifndef Movement_h
#define Movement_h

#include "UltraSonicSensor.h"

//used for the motors to control them
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

class Movement
{
  private:
  //defining the speeds of the smart car robot with separated directional speeds
  int carForwardSpeed = 110;
  int leftWheelSpeed = 185;
  int rightWheelSpeed = 200;
  
  public:
  void left();
  void right();
  void backward();
  void forward();
  void stop();
};

#endif
