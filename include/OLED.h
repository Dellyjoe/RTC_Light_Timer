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

void OLEDclockset(); //Not in a class Because this is used for an interrupt function it needs to be global