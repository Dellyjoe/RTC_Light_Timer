// Programmer: Joseph __Vitale
// Start Date: 03/15/19
// Completion Date: n/A
// Discription: This project will be able to display current time, set relay on/off
// time, the use of pots and buttons to navigate around the OLED display and set
// time to use for a timer.

#include <Arduino.h>
#include <potentiometer.h>
#include <OLED.h>
#include <rtc.h>
#include <LED.h>
#include <wire.h>
//*****************************************Declare*****************************//
// Function prototyping
void relaypin();
const int timer12 = 3;            // setting timer to ditigal pin 3
int replaystate = LOW;            // a state for the relay
unsigned long previousMillis = 0; // stores last vaule of relay
const long interval12 = 43200;         // setting interval to 12 hours

void timer();
//*****************************************Declare*****************************//
//******************************************Main******************************//

int main()
{
  Potentiometer PotentiometerO;
  OLED OLEDO;
  OLEDO.intdisplay();
  displaytime();
  ledblink();
  timer(); // Will this allow while loop to run or will it not before the void loop will not end?

  while (true)
  {

    PotentiometerO.getpot();
    OLEDO.OLEDdraw(PotentiometerO.getpot());
  }
  return (0);
} // end int main
//******************************************Main******************************//
//******************************************Setup*****************************//
void relaypin()
{
  // set the digital relay pin an output
  pinMode(timer12, OUTPUT); // setting pin 3 to an output pin
} //end relaypin
//******************************************Setup*****************************//
//*****************************************Functions**************************//
void timer()
{
  //check to see if it is time to turn on the relay
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval12)
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