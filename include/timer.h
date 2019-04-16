#include <Arduino.h>
#include <G_structure.h>
class Timerhour
{
private:
  const int timer12 = 13;
  int runingtimer;
  int replaystate = LOW;            // init state for the relay
  unsigned long previousMillis = 0; // stores last updated vaule of relay
public:
  void setuptimer();
  int timer(timeralarmpara Timervalues);
  unsigned long timerinterval = 10000; // Interval for relay blink
  String getRelayString();
}; // end class LED
