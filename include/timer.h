class Timer12hour
{
private:
  const int timer12 = 13;
  const long interval12 = 10000; // Interval for LED blink
  int runingtimer;
  //char timeron;

public:
  void setuptimer();
  int timer();
}; // end class LED
