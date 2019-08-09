#include <stdlib.h>

//TODO     potentiometer plus-minus star-speed (change prescaler divider in Timer)

//=======================INIT IN-OUT======================================================

#define DRIVER_RA_DIR 12 //PB4
#define DRIVER_RA_STEP 13 //PB5
//#define DRIVER_DEC_DIR 10 //PB2
//#define DRIVER_DEC_STEP 11 //PB3

//#define BUTTON_GOTO_SYNC 5 //PD5
//#define BUTTON_GOTO_SYNC_LED 3 //PD3

//#define BUTTON_DEC_INVERT_DIR 4 //PD4 BTN
//#define BUTTON_DEC_INVERT_DIR_LED 2 //PD2

//PULT
//#define BUTTON_RA_FORWARD 7 //PD7
//#define BUTTON_RA_BACKWARD 6 //PD6
//#define BUTTON_DEC_FORWARD 9 //PB1
//#define BUTTON_DEC_BACKWARD 8 //PB0

//========================================SKY MATH=========================================

//Floats have only 6-7 decimal digits of precision
//you can get more precision by using a double (e.g. up to 15 digits), on the Arduino, double is the same size as float!

//max 4000 ticks per second for Arduino 16MHz, http://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html

//#define STARDAY_us = 86164090531L //micro second in star-day

// тиков двигателя на полный оборот монти (зависит от редукции)
// 130(червь)* XXX (ремень)*400(шагов на 1 оборот ШД)* 32(микрошаг DRIVER_MICROSTEP_X=32)
//#define RA_microticks_per_revolution  4608000L; //ось прямого восхождения 
 
   

void setup() { 
  MOTOR_init();  
}

void loop() {
  TIMEMACHINE_loop();
}
