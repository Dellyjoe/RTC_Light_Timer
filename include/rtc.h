// CONNECTIONS:
// DS3231 SDA --> SDA
// DS3231 SCL --> SCL
// DS3231 VCC --> 3.3v or 5v
// DS3231 GND --> GND
#include <Wire.h>
#include <RTClib.h>

void initializeRTC();
void displaytime();

struct rtcparameters
{
};