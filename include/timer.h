#include <Arduino.h>

class Timer12hour
{
private:
  const int timer12 = 13;
  const long interval12 = 10000; // Interval for relay blink
  int runingtimer;
  int replaystate = LOW;            // init state for the relay
  unsigned long previousMillis = 0; // stores last updated vaule of relay
public:
  void setuptimer();
  int timer();
  String getRelayString();
}; // end class LED
