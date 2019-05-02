#RTC_Light_Timer

Author: Joseph Vitale

Description: This project will be able to display current timer time left, set relay on/off, the use of pots and buttons to navigate around the OLED display and set time RTC for relay switch.

 Any RTC is not needed to make this project function as described above. It would be simpler to just use this Ticker.h. You would set current ticker value to 12 hours and display that on the OLED. Still give functionality of being able to use buttons, pots etc... Ticker.h could be used with the RTC function. When RTC == a set time then it triggers the relay open/close.


Current coding Task to work on
- [ ] More Struct to timer.h, This is beacuse it is the same funtion. You don't need different funtions to be different files. 
- [ ] Get timerinterval to only turn on relay when Timervalues.clockset is = to current clock time.
    - convert Timervalues.clockset into hour() for comparability 
- [ ] In sendvaluestimer funtion figure out how to pass both variables to timer funtion 
    - Will have to get current coded struct to work
- [ ] Have potvalue set the time of the timer to go off when RTC clock hits that time
- [ ] Have clockalarm activate relay for the amount of time that timer is set to
- [ ] Clean up code

Ordered list on things to complete for this project, code based:
- [ ] Display current timer on main OLED screen
- [ ] Get clocktimerset funtion into a class 
- [x] Decide what RTC function to go with. 
    - Will have the time set automautomatically, and use clockalrm to activate on relay 
- [x] Get RTC working and displayed on the OLED
- [ ] Strip away all code that isn't necessary 

Functionality:
- [x] Use toggle switch to interrupted the OLED to display set timer, set clock 
- [x] Being able to Display current time and timer
- [ ] Programmable clockalrm and timer length 
- [ ] When clock setpoint = clockalarm throw relay to turn on a LED light for the set amount of time
- [ ] add SparkFun Soil Moisture Sensor, to understand want to water your plants

Hardware:
- [x] One pot to set timer setpoint
- [x] One OLED
- [x] A Microcontroller
- [x] one toggle switch for OLED
- [x] 3v Battery for RTC
- [x] 5v/1A AC charger with breadboard plug
- [x] A button to submit new values to Timer

Explantion of each funtion and component:

OLED driver:
- U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void OLED(int potvalue); 
- Creating a function for the display using Library u8g2. This function has one Parameter that is being passed in that is an int, I'm passing a value of potvalue which is grabbed from the return int value in function getpot. The value potvalue is then printed on the OLED screen which looks like the following "Pot Value" Value "%".

int getpot(); 

- This function is to read an analog pin on the Teensy. I picked A0 to start with, because it is the first analog pin on the Teensy - this is pin 14. I then map the values from 0-1023 on the pot to 0-100, this is something I will use later. With every change in 1% will be a change in setting the time in the RTC. 


