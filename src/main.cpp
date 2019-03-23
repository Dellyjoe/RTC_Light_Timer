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
//*****************************************Declare*****************************//
// Function prototyping
//*****************************************Declare*****************************//
//******************************************Main******************************//
Potentiometerread Potentiometerobject;
int main()
{
  intdisplay();
  displaytime();
  
  while (true)
  {
    
    Potentiometerobject.getpot();
    OLED(getpot());
  }
  return (0);
}
//******************************************Main******************************//
//******************************************Setup*****************************//

//******************************************Setup*****************************//
