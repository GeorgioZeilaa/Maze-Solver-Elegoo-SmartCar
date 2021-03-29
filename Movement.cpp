#include "Movement.h"

void Movement::left()
{
  analogWrite(ENA, leftWheelSpeed);
  analogWrite(ENB, leftWheelSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
}

void Movement::right()
{
  analogWrite(ENA, rightWheelSpeed);
  analogWrite(ENB, rightWheelSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Movement::backward()
{
  analogWrite(ENA, rightWheelSpeed);
  analogWrite(ENB, rightWheelSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Movement::forward()
{
  //using forward speed and turning right code since it will be used to rotate 180 degrees direction
  analogWrite(ENA, carForwardSpeed);
  analogWrite(ENB, carForwardSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Movement::stop()
{
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}
