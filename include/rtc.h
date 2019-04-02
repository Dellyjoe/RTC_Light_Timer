#include <TimeLib.h>   // Teensy 3.0's RTC
#include <DS1307RTC.h> // a basic DS1307 library that returns time as a time_t
#include <Wire.h>

time_t getTeensy3Time();
unsigned long processSyncMessage();
/*  code to process time sync messages from the serial port   */

// single character message tags
#define TIME_HEADER "T" // Header tag for serial time sync message

//const int offset = -5;  // Eastern Standard Time (USA)
const int offset = -4; // Eastern Daylight Time (USA)

void intrtc();
void digitalClockDisplay();
void displaytime();
void printDigits(int digits);