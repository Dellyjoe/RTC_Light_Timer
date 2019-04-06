#include <U8g2lib.h> // OLED
#ifdef U8X8_HAVE_HW_I2C
#endif
#include <Wire.h>

class OLED
{
private:
public:
  void intdisplay();
  void OLEDdraw(int potvalue, int currenttimer, String RelayString);
}; // end class OLED

void OLEDflag();                  //Not in a class Because this is used for an interrupt function it needs to be global
int clocktimerset(int potvalue2); // I believe this can be in a class given it doesn't have anything to do with the interrupted