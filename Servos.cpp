#include "Servos.h"

void Servos::write(int angle)
{
  myServo.write(angle);//sets the position angle of the servo which has ultra-sonic attached to it
  delay(500);
}

void Servos::attach()
{
  myServo.attach(3);//attach servo on pin 3 to servo object
}
