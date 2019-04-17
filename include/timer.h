#include <Arduino.h>
#include <G_structure.h>
class Timerhour
{
private:
  const int timer12 = 13;
  int runingtimer;
  int replaystate = LOW;            // init state for the relay
  unsigned long previousMillis = 0; // stores last updated vaule of relay
  int timerinterval = 10000;        // Interval for relay blink
public:
  void setuptimer();
  int timer(timeralarmpara &Timervalues);
  String getRelayString();
}; // end class LED
