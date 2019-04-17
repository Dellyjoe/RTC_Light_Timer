#include <timer.h>
#include <OLED_RTC.h>
#include <Wire.h>

//******************************************Setup*****************************//
void Timerhour::setuptimer()
{
  pinMode(timer12, OUTPUT); // setting pin 13 to an output pin
  Serial.begin(9600);
} //end setup

//*****************************************Functions**************************//
int Timerhour::timer(timeralarmpara &Timervalues)
{
  Timervalues.timer = timerinterval;
  Serial.print(timerinterval);
  Serial.println();
  delay(500);
  //check to see if it is time to turn on the relay
  unsigned long currentMillis = millis();
  if ((currentMillis - previousMillis) >= timerinterval)
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
    digitalWrite(timer12, replaystate); // setting the relay state to the relay pinout
  }
  runingtimer = (currentMillis - previousMillis) / 1000;

  return (runingtimer);
} // end timer

String Timerhour::getRelayString()
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
