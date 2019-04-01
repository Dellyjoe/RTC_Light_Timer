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
#include <timer.h>
#include <wire.h>

//******************************************Setup*****************************//
void setup()
{ //why do I have to have these here, to get the LED to blink if I have the code
  //in timer.cpp all ready
  const int timer12 = 13;
  pinMode(timer12, OUTPUT); // setting pin 13 to an output pin
} //end setup
//******************************************Setup*****************************//

//******************************************Main******************************//
void loop()
{
  Timer12hour Timer12hourO;
  Potentiometer PotentiometerO;
  OLED OLEDO;
  OLEDO.intdisplay();
  displaytime();
  Timer12hourO.timer();

  while (true)
  {

    PotentiometerO.getpot();
    OLEDO.OLEDdraw(PotentiometerO.getpot());
    break;
  }

} // end void loop
//******************************************Main******************************//
