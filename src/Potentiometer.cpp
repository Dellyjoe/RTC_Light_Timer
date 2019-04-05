#include <Arduino.h>
#include <potentiometer.h>
//*****************************************Functions**************************//
int Potentiometer::getpot()
{
  int potmap = map(pot, 0, 1023, 0, 100); // map values 0-100
  delay(250);
  return (potmap);
} // Close int getpot