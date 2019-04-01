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
{
  Timer12hour Timer12hour0; // Setting Object 0 for Timer12hour0
  Timer12hour0.setuptimer();

  OLED OLED0; // Setting Object 0 for OLED
  OLED0.intdisplay();
} //end setup
//******************************************Setup*****************************//

//******************************************Main******************************//
void loop()
{
  Timer12hour Timer12hour1; // Setting Object 0 for Timer12hour1
  Potentiometer Potentiometer0; // Setting Object 0 for Potentiometer0

  displaytime();
  Timer12hour1.timer();
  OLED OLED1; // Setting Object 1 for OLED
  while (true)
  {

    Potentiometer0.getpot();
    OLED1.OLEDdraw(Potentiometer0.getpot());
    break;
  }

} // end void loop
//******************************************Main******************************//
