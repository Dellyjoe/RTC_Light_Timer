#include <Arduino.h>
#include <G_structure.h>
class Timer12hour
{
private:
  const int timer12 = 13;
  int runingtimer;
  int replaystate = LOW;               // init state for the relay
  unsigned long timerinterval = 10000; // Interval for relay blink
  unsigned long previousMillis = 0;    // stores last updated vaule of relay
public:
  void setuptimer();
  int timer();
  String getRelayString();
}; // end class LED
