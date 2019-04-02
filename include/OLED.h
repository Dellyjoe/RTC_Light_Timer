#include <U8g2lib.h> // OLED

#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

class OLED
{
private:
public:
  void intdisplay();
  void OLEDdraw(int potvalue, int currenttimer);
}; // end class OLED