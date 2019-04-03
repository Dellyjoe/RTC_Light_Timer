#include <Arduino.h>

class Potentiometer
{
private:
  const int pot = analogRead(0); // Local varable pot on pin A0
public:
  int getpot();
}; // end Class Potentiometerread