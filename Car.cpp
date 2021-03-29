#include "Car.h"

//default library used for the IR remote
#include <IRremote.h>

//for the remote to define the PIN and initialisation
#define RECV_PIN 12
#define S 16712445
#define UNKNOWN_S 3622325019
IRrecv irrecv(RECV_PIN);
decode_results results;

void Car::setup()
{
  ultraSonicSensor.attachServo();//to be able to control the servo
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  carMovement.stop();//making sure the car is not moving so it is able to scan the middle distance when it runs run function
  irrecv.enableIRIn();//to be able to use the IR Remote
}

void Car::run()
{
  unsigned long val;
  while(value == 0)//while nothing is being received by the remote keep going
  {
      firstRun();//to run the normal maze solving

      if(irrecv.decode(&results))//when received an OK button then stop moving indicating end of maze
      {
        val = results.value;//to check the value received from remote
        Serial.println(val);
        irrecv.resume();
        if(val == S || val == UNKNOWN_S)//if OK button pressed
        {
          Serial.println("VALUE IS SET TO 1");
          value = 1;  
        }
      }
  }
  if(value == 1)//first time OK pressed indicating end of maze
  {
    Serial.println("STOP");
    value = 2;
    if(value == 2)//set value to 2 so it will not run stop every time it loops since it wont meet the value is 1 condition
    {
      carMovement.stop();//to stop the car as it is at the end of maze
    }
  }

  if(irrecv.decode(&results) && value == 2)//when the second OK button press is received and when the first OK was pressed since value is 2
  {
    //to run through the maze for the final time since it would have known the shortest path from the exploration run
    finalRun();
    Serial.println("FINAL RUN");
  }
}

void Car::firstRun()
{
  //to scan the obstacle in-front
  middleDistance = ultraSonicSensor.scanMiddle();
  
  if(middleDistance <= 25)//when an object is detected
  {
    carMovement.stop();

    //turn the servo to the left and scan distance
    leftDistance = ultraSonicSensor.scanLeft();

    //turn the servo to the right and scan distance
    rightDistance = ultraSonicSensor.scanRight();
    
    delay(500);
    //reset servo back to centre
    ultraSonicSensor.scanDistance(90);

    if(rightDistance > 50 && leftDistance > 50)//both left and right have no obstacles
    {
      lsrbAlgorithm.increment('L');//use to find populate array of char for path
      carMovement.left();//prefer to go left
      delay(200);
    }
    else if(rightDistance <= 25 && leftDistance <= 25) //if both left and right contain an obstacle then move back
    {
      //use to find populate array of char for path
      lsrbAlgorithm.increment('B');
      lsrbAlgorithm.increment('S');
      carMovement.backward();
      delay(500);
    }    
    else if(rightDistance < leftDistance)//only left side has no obstacle
    {
      lsrbAlgorithm.increment('L');//use to find populate array of char for path
      carMovement.left();
      delay(200);
    }
    else if(rightDistance > leftDistance)//only right side has no obstacle
    {
      lsrbAlgorithm.increment('R');//use to find populate array of char for path
      carMovement.right();
      delay(200);
    }
    else
    {
      carMovement.forward();//if the right and left is clear then move forward
    }
  }
  else
  {
    //to go straight, no obstacle in-front
    carMovement.forward();
  }
}

void Car::finalRun()
{
  middleDistance = ultraSonicSensor.scanMiddle();//to measure in-front of the robot car for obstacle

  if(middleDistance <= 20)//when an object is detected
  {
    carMovement.stop();//to stop the smart car as there is an obstacle in-front of it
    char direction = lsrbAlgorithm.receive();//to receive the next command from the arranged path
    
    if(direction == 'L')
    {
      carMovement.left();
      delay(200);
    }
    if(direction == 'R')
    {
      carMovement.right();
      delay(125);
    }
    if(direction == 'B')
    {
      carMovement.backward();
      delay(200);
    }
  }
  else
  {
    carMovement.forward();//to go forward when there are no objects
  }
}
