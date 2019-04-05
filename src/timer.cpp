#include <timer.h>
#include <Wire.h>
//*****************************************Declare*****************************//
unsigned long previousMillis = 0; // stores last updated vaule of relay
//******************************************Setup*****************************//
void Timer12hour::setuptimer()
{
  pinMode(timer12, OUTPUT); // setting pin 13 to an output pin
} //end setup

//*****************************************Functions**************************//
int Timer12hour::timer()
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
  runingtimer = (currentMillis - previousMillis) / 1000;

  return (runingtimer);
} // end timer

String Timer12hour::getRelayString()
{
  if (replaystate == LOW)
  {
    return "OFF";
  }
  else if (replaystate == HIGH)
  {
    return "ON";
  }
  else
  {
    return "UNKNOWN";
  }
}
