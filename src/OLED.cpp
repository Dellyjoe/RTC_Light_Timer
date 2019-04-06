#include <OLED.h>
#include <Potentiometer.h>
#include <wire.h>

//******************************************Declare*****************************//
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
//******************************************Setup*****************************//
void OLED::intdisplay()
{
    u8g2.begin(); // Start the Library code for the OLED
} // end void OLED

//*****************************************Functions**************************//
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

void OLEDflag()
{
    while (digitalRead(0) == HIGH)
    {
        Potentiometer Potentiometer1;           // why should I use a different Object here ? is it because it is a saporate .cpp file?
        clocktimerset(Potentiometer1.getpot()); // playing around with how I will change the timer vaules
    }
} // end void OLEDflag

int clocktimerset(int pv)
{
    u8g2.clearBuffer(); // clears current display
    u8g2.drawStr(0, 10, "Set Clock:");
    u8g2.drawStr(0, 25, "Set Timer");
    u8g2.setCursor(85, 25); // set cursor location
    u8g2.print(pv);
    u8g2.sendBuffer();
    delay(500); // Needs to change, I can't have my timer get delayed  because I want to change the time... Think about?
    return (0);
} //end void clocktimerset