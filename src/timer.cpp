#include <timer.h>
#include <Wire.h>
//*****************************************Declare*****************************//
int replaystate = LOW;            // init state for the relay
unsigned long previousMillis = 0; // stores last updated vaule of relay
//*****************************************Declare*****************************//
//******************************************Setup*****************************//
void Timer12hour::setuptimer()
{
  pinMode(timer12, OUTPUT); // setting pin 13 to an output pin
} //end setup
//******************************************Setup*****************************//
//*****************************************Functions**************************//
void Timer12hour::timer()
{
  //check to see if it is time to turn on the relay
  unsigned long currentMillis = millis();
  if ((currentMillis - previousMillis) >= interval12)
  {
    // save the last time you turned on the relay
    previousMillis = currentMillis;

    // if the relay is off turn it on and vice-versa:
    if (replaystate == LOW)
    {

      replaystate = HIGH;
    }
    else
    {

      replaystate = LOW;
    }
    digitalWrite(timer12, replaystate); // setting the relay state to the realy pinout
  }
} // end timer
  //*****************************************Functions**************************//