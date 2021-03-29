/*
  Car.h - Library for controlling the smart robot car.
*/
#ifndef Car_h
#define Car_h

//liraries used for the movement and for the algorithm which helps to find the shortest path
#include "Movement.h"
#include "LSRBAlgorithm.h"

class Car
{
  private:
  //initialising objects
  Movement carMovement;
  UltraSonicSensor ultraSonicSensor;
  LSRBAlgorithm lsrbAlgorithm;

  //variables used to keep track of left, right and middle distances
  int rightDistance = 0, leftDistance = 0, middleDistance = 0;

  //for ultra-sonic sensor
  int Echo = A4;//receiver
  int Trig = A5;//transmitter

  //used to keep track of the OK remote press in the run loop
  int value = 0;
  
  public:
  void setup();
  void run();
  void firstRun();//exploratory path to check what is the shortest
  void finalRun();//using the explored path to use the shortest direction
};

#endif
