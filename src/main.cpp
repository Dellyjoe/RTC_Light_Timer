// Programmer: Joseph __Vitale
// Start Date: 03/15/19
// Completion Date: n/A
// Discription: This project will be able to display current time, set relay on/off
// time, the use of pots and buttons to navigate around the OLED display and set
// time to use for a timer.

#include <Arduino.h>
#include <Potentiometer.h>
#include <OLED.h>
#include <TimeLib.h> // Teensy 3.0's RTC

/*  code to process time sync messages from the serial port   */
#define TIME_HEADER "T" // Header tag for serial time sync message

//*****************************************Declare*****************************//
// Function prototyping

void setup();
void digitalClockDisplay();
time_t getTeensy3Time();
unsigned long processSyncMessage();
//*****************************************Declare*****************************//
//******************************************Main******************************//
int main()
{
  setup();
  intdisplay();

  if (Serial.available())
  {
    time_t t = processSyncMessage();
    if (t != 0)
    {
      Teensy3Clock.set(t); // set the RTC
      setTime(t);
    }
  }
  digitalClockDisplay();
  //delay(1000);
  while (true)
  {
    getpot();
    OLED(getpot());
  }

  return (0);
}
//******************************************Main******************************//
//******************************************Setup*****************************//
void setup()
{
  // set the Time library to use Teensy 3.0's RTC to keep time
  setSyncProvider(getTeensy3Time);

  Serial.begin(115200); // Setting up the Serial Terminal
  while (!Serial)
    ; // Wait for Arduino Serial Monitor to open
  delay(100);
  if (timeStatus() != timeSet)
  {
    Serial.println("Unable to sync with the RTC");
  }
  else
  {
    Serial.println("RTC has set the system time");
  }
} // Close Void Setup
//******************************************Setup*****************************//
//*****************************************Functions**************************//

void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());
  Serial.print(": ");
  Serial.print(day());
  Serial.print("/");
  Serial.print(month());
  Serial.print("/");
  Serial.print(year());
  Serial.println();
}

time_t getTeensy3Time()
{
  return Teensy3Clock.get();
}
unsigned long processSyncMessage()
{
  unsigned long pctime = 0L;
  const unsigned long DEFAULT_TIME = 1553130740; // March 20, 2019 9:12:20 PM

  if (Serial.find(TIME_HEADER))
  {
    pctime = Serial.parseInt();
    return pctime;
    if (pctime < DEFAULT_TIME)
    {              // check the value is a valid time (greater than Jan 1 2013)
      pctime = 0L; // return 0 to indicate that the time is not valid
    }
  }
  return pctime;
}
//*****************************************Functions**************************//
