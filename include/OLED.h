#include <U8g2lib.h> // OLED

#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

void intdisplay();
void OLED(int potvalue);