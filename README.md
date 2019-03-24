#RTC_Light_Timer
Author: Joseph Vitale

Discription: This project will be able to display current time, set relay on/off time, the use of pots and buttons to navigate around the OLED display and set time to use for a timer.

*Functionality:
    -Display current time on OLED
    -Display Timmer set time on OLED
    -Have the ability to navagate through the OLED with a press of a button, with hold ability
    -Being able to set current time and current timmer time with use of button
    -When timmer setpoint = time throw relay to turn on a LED light for 12 hours

*Hardware:
    -One or three pots to set timmer setpoint
    -One OLED - smaller the better
    -One Microcontroller 
    -one button

Explantion of each funtion:

OLED driver:
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


* void setup();
    Setup is the initialization of devices. 
        -U8g2.begin(); : Starts the code that will initialize the display.

* void OLED(int potvalue); 
    Creating a function for the display using Library u8g2. This function has one Parameter that is being passed in that is an int, I'm passing a value of potvalue which is grabbed from the return int value in function getpot. The value potvalue is then printed on the OLED screen which looks like the following "Pot Value" Value "%".

* int getpot(); 
    This function is to read an analog pin on the Teensy. I picked A0 to start with, because it is the first analog pin on the Teensy - this is pin 14. I then map the values from 0-1023 on the pot to 0-100, this is something I will use later. With every change in 1% will be a change in setting the time in the RTC. 