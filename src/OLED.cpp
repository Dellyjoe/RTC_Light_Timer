#include <OLED.h>

//******************************************Declare*****************************//
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

//******************************************Setup*****************************//
void OLED::intdisplay()
{
    u8g2.begin(); // Start the Library code for the OLED

} // end void OLED
//******************************************Main******************************//
void OLED::OLEDdraw(int potvalue, int currenttimer, String RelayString)
{
    u8g2.clearBuffer();                 // clear the internal memory
    u8g2.setFlipMode(1);                // Flips display 180 (1) = True
    u8g2.setFont(u8g2_font_koleeko_tr); // choose a suitable font
    u8g2.drawStr(0, 10, "Pot Value:");
    u8g2.setCursor(70, 10); // set cursor location
    u8g2.print(potvalue);   // print at current cursor location
    u8g2.drawStr(85, 10, " % ");
    u8g2.drawStr(0, 25, "Relay State:");
    u8g2.setCursor(85, 25); // set cursor location
    u8g2.print(RelayString);
    u8g2.drawStr(0, 50, "Runing Timer(s):");
    u8g2.setCursor(0, 60);    // set cursor location
    u8g2.print(currenttimer); // print at current cursor location
    u8g2.sendBuffer();        // transfer internal memory to the display
} // end void OLED
