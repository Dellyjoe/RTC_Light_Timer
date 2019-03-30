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
//#include <LED.h>
#include <wire.h>
//*****************************************Declare*****************************//
// Function prototyping
const int timer12 = 13;           // setting timer to ditigal pin 13 for LED example
int replaystate = LOW;            // a state for the relay
unsigned long previousMillis = 0; // stores last updated vaule of relay
const long interval12 = 2000;
void timer();
//*****************************************Declare*****************************//
//******************************************Setup*****************************//
void setup()
{
  // set the digital relay pin an output
  pinMode(timer12, OUTPUT); // setting pin 3 to an output pin
} //end setup
//******************************************Setup*****************************//
//******************************************Main******************************//

void loop()
{
  setup();
  Potentiometer PotentiometerO;
  OLED OLEDO;
  OLEDO.intdisplay();
  displaytime();
  //ledblink();
  timer();

  //while (true)
  //{

  PotentiometerO.getpot();
  OLEDO.OLEDdraw(PotentiometerO.getpot());
  //}

} // end int main
//******************************************Main******************************//
//*****************************************Functions**************************//
void timer()
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