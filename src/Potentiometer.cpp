#include <Arduino.h>
#include <potentiometer.h>


  int Potentiometer::getpot()
  {
    int pot = analogRead(0);                // Local varable pot on pin A0
    int potmap = map(pot, 0, 1023, 0, 100); // map values 0-100
    delay(250);
    return (potmap);
  } // Close int getpot