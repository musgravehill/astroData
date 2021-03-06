#include <stdlib.h>
#include <EEPROM.h>


//TODO     potentiometer plus-minus star-speed (change prescaler divider in Timer)

//=======================INIT IN-OUT======================================================

#define DRIVER_RA_DIR 12 //PB4
#define DRIVER_RA_STEP 13 //PB5

#define RA_speed_inc 5 //PD5 BTN
#define RA_speed_dec 4 //PD4 BTN
#define DRIVER_DEC_DIR 10 //PB2
#define DRIVER_DEC_STEP 11 //PB3

//#define BUTTON_GOTO_SYNC_LED 3 //PD3
//#define BUTTON_DEC_INVERT_DIR_LED 2 //PD2

//PULT
#define BUTTON_RA_FORWARD 7 //PD7
#define BUTTON_RA_BACKWARD 6 //PD6
#define BUTTON_DEC_FORWARD 9 //PB1
#define BUTTON_DEC_BACKWARD 8 //PB0

#define SYS_STATE_STAR_TRACKING 0
#define SYS_STATE_PULT_RA_FORWARD 1
#define SYS_STATE_PULT_RA_BACKWARD 2
#define SYS_STATE_PULT_DEC_FORWARD 3
#define SYS_STATE_PULT_DEC_BACKWARD 4
volatile uint8_t SYS_STATE = SYS_STATE_STAR_TRACKING;
volatile uint8_t SYS_STATE_PREV = SYS_STATE_STAR_TRACKING;
uint16_t PULT_SPEED_COEFF = 2;
#define PULT_SPEED_COEFF_MIN 2
#define PULT_SPEED_COEFF_MAX 1000
volatile uint16_t TIMER_tick_counter = 0;

//========================================SKY MATH=========================================

//Floats have only 6-7 decimal digits of precision
//you can get more precision by using a double (e.g. up to 15 digits), on the Arduino, double is the same size as float!

//#define STARDAY_us = 86164090531L //micro second in star-day

// тиков двигателя на полный оборот монти (зависит от редукции)
// 144(червь)* 40\16 (ремень)* 200(шагов на 1 оборот ШД)* 32(микрошаг DRIVER_MICROSTEP_X=32)
//#define RA_microticks_per_revolution  2304000L; //ось прямого восхождения

uint16_t TIMER_OCR1A = 2336; //Верхняя граница счета. Диапазон от 0 до 65535.

uint32_t TIMEMACHINE_prevMicros_83ms = 1L;
uint32_t TIMEMACHINE_prevMicros_313ms = 1L;
uint32_t TIMEMACHINE_prevMicros_873ms = 1L;

void setup() {
  //Serial.begin(9600);
  BUTTON_init();
  MOTOR_init();
}

void loop() {
  TIMEMACHINE_loop();
}
