#include <TimeLib.h> // Teensy 3.0's RTC
time_t getTeensy3Time();
unsigned long processSyncMessage();
/*  code to process time sync messages from the serial port   */
#define TIME_HEADER "T" // Header tag for serial time sync message

void intrtc();
void digitalClockDisplay();
void displaytime();
