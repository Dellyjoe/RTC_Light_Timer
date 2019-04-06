#include <Arduino.h>
#include <potentiometer.h>
//*****************************************Functions**************************//
int Potentiometer::getpot1()
{
  int potmap1 = map(pot1, 0, 1023, 0, 100); // map values 0-100
  delay(250);
  return (potmap1);
} // Close int getpot

int Potentiometer::getpot2()
{
  int potmap2 = map(pot2, 0, 1023, 0, 100); // map values 0-100
  delay(250);
  return (potmap2);
} // Close int getpot
