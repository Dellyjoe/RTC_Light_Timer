#include <rtc.h>

//*****************************************Functions**************************//
void intrtc()
{
  // set the Time library to use Teensy 3.0's RTC to keep time
  setSyncProvider(getTeensy3Time);

  Serial.begin(115200); // Setting up the Serial Terminal
}

void displaytime()
{
  intrtc();
  if (Serial.available())
  {
    time_t t = processSyncMessage();
    if (t != 0)
    {
      Teensy3Clock.set(t); // set the RTC
      setTime(t);
      //adjustTime(offset * SECS_PER_HOUR);
    }
  }
  digitalClockDisplay();
  //delay(1000);
}
//*****************************************Functions**************************//
void digitalClockDisplay()
{
  //digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(": ");
  Serial.print(day());
  Serial.print("/");
  Serial.print(month());
  Serial.print("/");
  Serial.print(year());
  Serial.println();
}

void printDigits(int digits)
{
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
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
} //*****************************************Functions**************************//
