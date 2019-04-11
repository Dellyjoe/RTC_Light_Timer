// Programmer: Joseph __Vitale
// Start Date: 03/15/19
// Completion Date: n/A
// Discription: This project will be able to display current time, set relay on/off
// time, the use of pots and buttons to navigate around the OLED display and set
// time to use for a timer.

#include <potentiometer.h>
#include <OLED_RTC.h>
#include <timer.h>
#include <avr/io.h>        // interrupt
#include <avr/interrupt.h> // interrupt
//******************************************Declare*****************************//
Timer12hour Timer12hour0; // Setting Object 0 for Timer12hour0
OLED OLED0;               // Setting Object 0 for OLED
//******************************************Setup*****************************//
void setup()
{
  Timer12hour0.setuptimer();
  OLED0.intdisplay();
  pinMode(0, INPUT);
  attachInterrupt(digitalPinToInterrupt(0), OLEDflag, HIGH);       // Setting interrupt pin D0
  attachInterrupt(digitalPinToInterrupt(1), SendValuesflag, HIGH); // Setting interrupt pin D1
} //end setup
//******************************************Main******************************//
void loop()
{
  Timer12hour0.timer();
  OLED0.OLEDdraw(Timer12hour0.timer(), Timer12hour0.getRelayString());
} // end void loop
