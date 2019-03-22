#include <Arduino.h>
#include <Potentiometer.h>

int getpot()
{
  int pot = analogRead(0);                // Local varable pot
  int potmap = map(pot, 0, 1023, 0, 100); // map values 0-100
  delay(250);
  return (potmap);
} // Close Void getpot