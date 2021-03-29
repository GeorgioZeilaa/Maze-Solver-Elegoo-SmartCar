/*
  LSRBAlgorithm.h - Library for choosing a more efficient path.
*/
#ifndef LSRBAlgorithm_h
#define LSRBAlgorithm_h

#include <Arduino.h>

class LSRBAlgorithm
{ 
  private:
  char path [30];
  int path_size = 0;//to know where we are in the array of char
  int receive_index = 0;//to receive the correct value when going in the maze for the final time
  
  public:
  void increment(char letter);
  int arrange();
  char receive();
};

#endif
