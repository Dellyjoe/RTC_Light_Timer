#include <OLED.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

void OLED::intdisplay()
{
    u8g2.begin(); // Start the Library code for the OLED
} // end void OLED

void OLED::OLEDdraw(int potvalue)
{
    u8g2.clearBuffer();                 // clear the internal memory
    u8g2.setFlipMode(1);                // Flips display 180 (1) = True
    u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
    u8g2.drawStr(0, 10, "Pot Value:");
    u8g2.setCursor(60, 10); // set cursor location
    u8g2.print(potvalue);   // print at current cursor location
    u8g2.drawStr(75, 10, " % ");
    u8g2.sendBuffer(); // transfer internal memory to the display
} // end void OLED
