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
  timer();

  while (true)
  {

    PotentiometerO.getpot();
    OLEDO.OLEDdraw(PotentiometerO.getpot());
  }
  return (0);
} // end int main
//******************************************Main******************************//
//******************************************Setup*****************************//
//******************************************Setup*****************************//
//*****************************************Functions**************************//
void timer()
{
  const int timer12 = 3;// setting timer to ditigal pin 3
  pinMode(timer12, OUTPUT); // setting pin 3 to an output pin
  digitalWrite(timer12, HIGH);// setting pin 3 to HIGH (1)
  delay(43200); // High for 12 hours
  digitalWrite(timer12, LOW);//setting pin 3 to LOW (0)
  delay(43200); // LOW for 12 hours
}// end timer
//*****************************************Functions**************************//