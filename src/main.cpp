// Programmer: Joseph __Vitale 
// Start Date: 03/15/19
// Completion Date: n/A 
// Description: Timmer; This project will be able to display current time, set relay on/off
// time, the use of pots and buttons to navagate around the OLED display/set time and timmer. 

#include <Arduino.h>            // Teensy is Arduino Based
#include <U8g2lib.h>            // OLED
#include <TimeLib.h>            // RTC

#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

//*****************************************Declare*****************************//
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
// Function prototyping  
void setup();
void OLED(int potvalue); 
int getpot(); 
//*****************************************Declare*****************************//
//******************************************Main******************************//
int main (){
  setup();
  
    while(true)
    {
    getpot(); // <-- Why do I not have to return a vaule?
    OLED(getpot());
    
    }
return (0);
}
//******************************************Main******************************//
//******************************************Setup*****************************//
void setup() {
  u8g2.begin();        // Start the Library code for the OLED
  Serial.begin(38400); // Sets the data rate in bits per second (baud) 
} // Close Void Setup
//******************************************Setup*****************************//
//*****************************************Functions**************************//
void OLED(int potvalue){
    u8g2.clearBuffer();  // clear the internal memory
    u8g2.setFlipMode(1); // Flips display 180 (1) = True 
    u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
    u8g2.drawStr(0,10,"Pot Value:");
    u8g2.setCursor(60, 10); // set cursor location
    u8g2.print(potvalue); // print at current cursor location
    u8g2.drawStr(70,10," % ");
    u8g2.sendBuffer(); // transfer internal memory to the display
  } // close void OLED

 int getpot(){ 
  int pot = analogRead(0); // Local varable pot 
  int potmap = map(pot,0,1023,0,100); // map values 0-100
    delay(250);
    return (potmap);
 } // Close Void getpot
//*****************************************Functions**************************//

