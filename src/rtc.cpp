#include <rtc.h>

//*****************************************Setup**************************//
void intrtc()
{
  // set the Time library to use Teensy 3.0's RTC to keep time
  setSyncProvider(getTeensy3Time);

  Serial.begin(115200); // Setting up the Serial Terminal
}
//*****************************************Functions**************************//
void displaytime()
{
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
}

void digitalClockDisplay()
{
  //digital clock display of the time
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());
  Serial.print(": ");
  Serial.print(month());
  Serial.print("/");
  Serial.print(day());
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
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

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
