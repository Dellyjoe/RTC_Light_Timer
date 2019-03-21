// Programmer: Joseph __Vitale 
// Start Date: 03/15/19
// Completion Date: n/A 
// Discription: This project will be able to display current time, set relay on/off 
// time, the use of pots and buttons to navigate around the OLED display and set
// time to use for a timer.

#include <Arduino.h>            // Teensy is Arduino Based
#include <U8g2lib.h>            // OLED
#include <TimeLib.h>            // Teensy 3.0's RTC 
/*  code to process time sync messages from the serial port   */
#define TIME_HEADER  "T"   // Header tag for serial time sync message


#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


//*****************************************Declare*****************************//
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
// Function prototyping  
void setup();
void OLED(int potvalue); 
int getpot(); 
void digitalClockDisplay();
time_t getTeensy3Time();
unsigned long processSyncMessage();
//*****************************************Declare*****************************//
//******************************************Main******************************//
int main (){
  setup();
   while(true)
    {
    getpot(); // <-- Why do I not have to return a vaule?
    OLED(getpot());

   if (Serial.available()) {
    time_t t = processSyncMessage();
    if (t != 0) {
      Teensy3Clock.set(t); // set the RTC
      setTime(t);
    }
  }
  digitalClockDisplay();  
  delay(1000);
    }
return (0);
}
//******************************************Main******************************//
//******************************************Setup*****************************//
void setup() {
  u8g2.begin();        // Start the Library code for the OLED
  // set the Time library to use Teensy 3.0's RTC to keep time
  setSyncProvider(getTeensy3Time);

  Serial.begin(115200); // Setting up the Serial Terminal 
  while (!Serial);  // Wait for Arduino Serial Monitor to open
  delay(100);
  if (timeStatus()!= timeSet) {
    Serial.println("Unable to sync with the RTC");
  } else {
    Serial.println("RTC has set the system time");
  }

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
    u8g2.drawStr(75,10," % ");
    u8g2.sendBuffer(); // transfer internal memory to the display
  } // close void OLED

 int getpot(){ 
  int pot = analogRead(0); // Local varable pot 
  int potmap = map(pot,0,1023,0,100); // map values 0-100
    delay(250);
    return (potmap);
 } // Close Void getpot

void digitalClockDisplay() {
  // digital clock display of the time
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());
  Serial.print(": ");
  Serial.print(day());
  Serial.print("/");
  Serial.print(month());
  Serial.print("/");
  Serial.print(year()); 
  Serial.println(); 
}

time_t getTeensy3Time()
{
  return Teensy3Clock.get();
}
unsigned long processSyncMessage() {
  unsigned long pctime = 0L;
  const unsigned long DEFAULT_TIME = 1553130740; // March 20, 2019 9:12:20 PM

  if(Serial.find(TIME_HEADER)) {
     pctime = Serial.parseInt();
     return pctime;
     if( pctime < DEFAULT_TIME) { // check the value is a valid time (greater than Jan 1 2013)
       pctime = 0L; // return 0 to indicate that the time is not valid
     }
  }
  return pctime;
}
//*****************************************Functions**************************//

