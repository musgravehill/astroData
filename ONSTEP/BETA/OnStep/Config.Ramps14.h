
// -----------------------------------------------------------------------------------
// Configuration for OnStep

/*
 * === USE AT YOUR OWN RISK ===
 * For more information on setting OnStep up see:
 *   https://groups.io/g/onstep/wiki/home
 *
 * Join the OnStep Groups.io at
 *   https://groups.io/g/onstep
 *
*/

// WARNING: Axis 1 steps/second [213.33333333333331] is usually between 20 and 120
// WARNING: Axis 2 steps/second [213.33333333333331] is usually between 20 and 120

// Here are the values you selected:
// Mount type: GEM
// Board: Ramps14
// Axis 1:
//   Worm wheel steps/rotation:  144.0
//   Transfer gear/pulley ratio: 2.5
//   Motor Steps/Rotation:       400
//   Microsteps when tracking:   128
//   Microsteps when slewing :   1
//   Stepper Driver Model:       LV8729
// Axis 2:
//   Worm wheel steps/rotation:  144.0
//   Transfer gear/pulley ratio: 2.5
//   Motor Steps/Rotation:       400
//   Microsteps when tracking:   128
//   Microsteps when slewing:    1
//   Stepper Driver Model:       LV8729
// Max Rate:                     48
// PEC Buffer Size:              600
// Based on what you entered, the values below were calculated:
// Please check they are as per the spreadsheet, and DO NO EXCEED the mechanical or electronic limits
// ===
// Axis 1
//   Pulse rate when tracking:   213.3 steps/second
//   Resolution when tracking:   0.070 arc second/step
//   Maximum Slew Rate:          0.41 degree/second
//   Motor speed when slewing:   24.4 RPM
// Axis 2
//   Pulse rate when tracking:   213.3 steps/second
//   Resolution when tracking:   0.070 arc second/step
//   Maximum Slew Rate:          0.41 degree/second
//   Motor speed when slewing:   24.4 RPM


// === CONFIGURATION START

#define Ramps14_ON
#ifdef  Ramps14_ON

// Mount type: default is _GEM (German Equatorial.) This allows Meridian flips and
// can be used for other mount types if that behaviour is desired.
// _FORK switches off Meridian Flips but allows travel across the Meridian.
// _ALTAZM is for Alt/Azm mounted scopes, e.g. Dobsonians
#define MOUNT_TYPE_GEM

// Microseconds per microstep default setting for gotos, can be adjusted for two
// times lower or higher at run-time
// Minimum* (fastest goto) is around 16, default=96 higher is ok
// * = Minimum can be lower, when both AXIS1/AXIS2_MICROSTEPS are used the compiler
// will warn you if it is too low
#define MaxRate                    48

// Axis1 is for RA/Az
// Calculated as (example for Losmandy G11)
//  stepper_steps * micro_steps * gear_reduction1 * (gear_reduction2/360)
//  400           * 32          * 1               *  360/360              = 12800
#define StepsPerDegreeAxis1        51200.00000

// Axis2 is for Dec/Alt
// Calculated as (example for Losmandy G11)
//  stepper_steps * micro_steps * gear_reduction1 * (gear_reduction2/360)
//  400           * 32          * 1               *  360/360              = 12800
#define StepsPerDegreeAxis2        51200.00000

// PEC, number of steps for a complete worm rotation (in RA),
// calculated as: (StepsPerDegreeAxis1*360)/gear_reduction2.
// Ignored on Alt/Azm mounts.
// Example for G11: (12800*360)/360 = 12800
#define StepsPerWormRotationAxis1  128000.0

// PEC, buffer size, max should be no more than 3384, your required buffer
// size >= StepsPerAxis1WormRotation/(StepsPerDegeeAxis1/240)
// for the most part this does not need to be changed, but adjust when needed.
// 824 seconds is the default.  Ignored on Alt/Azm mounts.
#define PECBufferSize              600

// Basic stepper driver mode setup
// If used, this requires connections M0, M1, and M2 on certain Pins, as per the 
// pinmap for both Axes
// Stepper driver models are as follows: DRV8825, A4988, LV8729, RAPS128, ST820, S109, TMC2208,
// The TMC2130 has several sub models: TMC2130 (spreadCycle,) TMC2130_QUIET (stealthChop tracking,)
// TMC2130_VQUIET (full stealthChop mode,) add _LOWPWR for 50% power during tracking
// (e.g.: TMC2130_QUIET_LOWPWR)
// Note: you can replace this section with the contents of "AdvancedStepperSetup.txt"

// Axis1 (RA/Azm):  Default _OFF, Stepper driver model (see above)
#define AXIS1_DRIVER_MODEL_OFF
// Axis1 (RA/Azm):  Default _OFF, Microstep mode when the scope is doing sidereal tracking
#define AXIS1_MICROSTEPS_OFF
// Axis1 (Dec/Alt): Default _OFF, Optional microstep mode used during gotos
// Optional microstep mode used during gotos (for example: AXIS1_MICROSTEPS_GOTO 2)
#define AXIS1_MICROSTEPS_GOTO_OFF

// Axis2 (Dec/Alt): Default _OFF, Stepper driver model (see above)
#define AXIS2_DRIVER_MODEL_OFF
// Axis2 (Dec/Alt): Default _OFF, Microstep mode when the scope is doing sidereal tracking
#define AXIS2_MICROSTEPS_OFF
// Axis2 (Dec/Alt): Default _OFF, Optional microstep mode used during gotos
#define AXIS2_MICROSTEPS_GOTO_OFF

// Light status LED by sink to ground (Pin ?), default=_ON.
// _ON and OnStep keeps this illuminated to indicate that the controller is active.
// When sidereal tracking this LED will rapidly flash
#define STATUS_LED_PINS_ON

// When OnStep powers up, it waits for a command to start an align sequence. Therefore, it does not
// start sidereal tracking automatically. This option starts sidereal tracking, and is very useful
// for initial testing, when you want to see if the controller is working.
#define AUTOSTART_TRACKING_ON

// Enables internal goto assist mount modeling (for Eq mounts), default=_OFF (Experimental)
// Note that Goto Assist in Sky Planetarium works even if this is off
#define ALIGN_GOTOASSIST_ON

// Default speed for Serial B and C ports, Default=9600
//#define SERIAL_B_BAUD_DEFAULT 9600
//#define SERIAL_C_BAUD_DEFAULT 9600

// ESP8266 reset and GPIO0 control, this sets run mode for normal operation.
// Uploading programmer firmware to the OpStep MCU can then enable sending new
// firmware to the ESP8266-01
// Pin ? (Aux1) for GPIO0 and Pin ? (Aux2) for Rst control.  Choose only one feature on Aux1/2.
#define ESP8266_CONTROL_OFF

// Strict parking, default=_OFF.  Set to _ON and unparking is only allowed if successfully parked.
// Otherwise unparking is allowed if at home and not parked (the Home/Reset command ":hF#" sets this state.) 
#define STRICT_PARKING_OFF

// ST4 interface on pins ?, ?, ?, ?.  Pin ? is RA- (West), Pin ? is Dec- (South), Pin ? is Dec+ (North),
// Pin ? is RA+ (East.)
// ST4_ON enables the interface, ST4_PULLUP enables the interface and any internal pullup resistors.
// It is up to you to create an interface that meets the electrical specifications of any connected device,
// use at your own risk.
// default=_OFF
#define ST4_PULLUP

// If SEPARATE_PULSE_GUIDE_RATE_ON is used the ST4 port is limited to guide rates <= 1X except when
// ST4_HAND_CONTROL_ON is used.
// Additionally, ST4_HAND_CONTROL_ON enables special features: Press and hold [E]+[W] buttons for > 2 seconds...
// In this mode [E] decreases and [W] increases guide rates (or if tracking is not on yet adjusts illuminated
// recticule brightness.)
// [S] for Sync (or Accept if in align mode.) [N] for Tracking on/off. -OR- Press and hold [N]+[S] buttons
// for > 2 seconds...
// In this mode [E] selects prior and [W] next user catalog item.
// [N] to do a Goto to the catalog item.  [S] for Sound on/off.
// The keypad returns to normal operation after 4 seconds of inactivity.
// ST4_HAND_CONTROL_ON also adds a 100ms de-bounce to all button presses.
// Finally, during a goto pressing any button aborts the slew.  If meridian flip paused at home, pressing any
// button continues.
// default=_ON
#define ST4_HAND_CONTROL_ON

// Pressing [N]+[S] together selects Catalog mode by default, unless the following parameter
// is set to _ON. If it is, then [N]+[S] selects Focuser mode.
// Catalog mode:
//   [E] select prior user catalog item
//   [W] select next user catalog item
//   [N] Goto to the catalog item
//   [S] Sound on/off
// Focuser mode:
//   [E] for Focuser1
//   [W] for Focuser2
//   [N] move in
//   [S] move out
#define ST4_HAND_CONTROL_FOCUSER_OFF

// Separate pulse-guide rate so centering and guiding do not disturb each other, default=_ON
#define SEPARATE_PULSE_GUIDE_RATE_ON

// Guide time limit (in seconds,) default=0 (no limit.)  A safety feature, some guides are started with one command
// and stopped
// with another.  // If the stop command is never received the guide will continue forever unless this is enabled.
#define GUIDE_TIME_LIMIT 0
// RTC (Real Time Clock) support, default=_OFF. Other options:
// RTC_DS3234: for a DS3234 on the default SPI interface pins (CS on pin 10 for MaxPCB)
// RTC_DS3231:for a DS3231 on the default I2C pins (also wire the SQW output to the PPS pin)
#define RTC_DS3231
// PPS use _ON or _PULLUP to enable the input and use the built-in pullup resistor.  Sense rising edge
// on PPS Pin in pinmap for precision clock source (e.g. GPS, or temperature compensated TCXO), default=_OFF
#define PPS_SENSE_ON

// PEC sense on Pin ? use _ON or _PULLUP to enable the input/use the built-in pullup resistor (digital input) or
// provide a comparison value (see below) for analog operation, default=_OFF
// Analog values range from 0 to 1023 which indicate voltages from 0-3.3VDC on the analog pin,
// for example "PEC_SENSE 600" would detect an index when the voltage exceeds 1.93V
// With either index detection method, once triggered 60s must expire before another detection can happen.
// This gives time for the index magnet to pass by the detector before another cycle begins.
// Ignored on Alt/Azm mounts.
#define PEC_SENSE_OFF

// PEC sense, rising edge (default with PEC_SENSE_STATE HIGH, use LOW for falling edge, ex. PEC_SENSE_ON).
// for optional PEC index
#define PEC_SENSE_STATE HIGH

// Switch for optional limit sense (stops gotos and/or tracking), default=_OFF
#define LIMIT_SENSE_OFF
// Default LOW for NO (normally open) limit switches which close when triggered, change this to HIGH if
// your switch is NC (normally closed) and only opens when triggered.
#define LIMIT_SENSE_STATE LOW

// BME280 I2C temperature, pressure and humidity sensor
#define WEATHER_BME280_OFF

// Light 2nd status LED by sink to ground (Pin ?), default=_OFF.
// _ON sets this to blink at 1 sec intervals when PPS is synced.  Turns off if tracking is stopped.
// Turns on during gotos.
#define STATUS_LED2_PINS_OFF

// Light reticule LED by sink to ground (Pin ?), default=_OFF.  (do not use with STATUS_LED2_PINS_ON)
// RETICULE_LED_PINS n, where n=0 to 255 activates this feature and sets default brightness
#define RETICULE_LED_PINS_OFF

// Sound/buzzer on Pin ?, default=_OFF.
// Specify frequency for a piezo speaker (for example "BUZZER 2000") or use BUZZER_ON for a piezo buzzer.
#define BUZZER_OFF

// Sound state at startup, default=_ON.
#define DEFAULT_SOUND_ON

// Optionally adjust tracking rate to compensate for atmospheric refraction, default=_OFF
// can be turned on/off with the :Tr# and :Tn# commands regardless of this setting
#define TRACK_REFRACTION_RATE_DEFAULT_OFF

// Set to _OFF and OnStep will allow Syncs to change pier side for GEM mounts (on/off), default=_ON
#define SYNC_CURRENT_PIER_SIDE_ONLY_OFF 

// Set to _ON and OnStep will remember the last auto meridian flip setting (on/off), default=_OFF
#define REMEMBER_AUTO_MERIDIAN_FLIP_OFF
// Set to _ON and OnStep will travel directly across a meridian flip without visiting the home position
// (on/off), default=_OFF (only applies if pause at home is disabled)
#define MERIDIAN_FLIP_SKIP_HOME_OFF

// Set to _ON and OnStep will remember the last meridian flip pause at home setting (on/off), default=_OFF
#define REMEMBER_PAUSE_HOME_OFF

// ADJUST THE FOLLOWING TO MATCH YOUR MOUNT ---------------------------------------------------------------
// set to _ON and OnStep will remember rates set in the ASCOM driver, Android App, etc. default=_OFF 
#define REMEMBER_MAX_RATE_OFF

// approximate number of degrees for full acceleration or deceleration:
// higher values=longer acceleration/deceleration
// Default=5.0, too low (about <1) can cause gotos to never end if micro-step mode switching is enabled.
#define DegreesForAcceleration   5.0

// approximate number of degrees required to stop when requested or if limit is exceeded during a slew:
// higher values=longer deceleration
// Default=1.0, too low (about <1) can cause gotos to never end if micro-step mode switching is enabled.
#define DegreesForRapidStop      1.0

// backlash takeup rate (in multipules of the sidereal rate): too fast and your motors will stall,
// too slow and the mount will be sluggish while it moves through the backlash
// for the most part this does not need to be changed, but adjust when needed.  Default=25
#define BacklashTakeupRate        25

// The two parameters below can be removed and settings in EEPROM will be used instead, be sure to set the Meridian
// limits in control software if you do this!  
// If you do not remove these lines Meridian limits will return to these defaults on power up.

// For gotos, how far past the meridian to allow before we do a flip (if on the East side of the pier)
// - a half hour of RA is the default = 30.  Sometimes used for Fork mounts in Align mode.
// Ignored on Alt/Azm mounts.
#define MinutesPastMeridianE      30

// As above, if on the West side of the pier.  If left alone, the mount will stop tracking when it hits the this
// limit. Sometimes used for Fork mounts in Align mode.
// Ignored on Alt/Azm mounts.
#define MinutesPastMeridianW      30

// Maximum allowed hour angle (+/-) under the celestial pole.  Default=12.  Ignored on Alt/Azm mounts.
// If left alone, the mount will stop tracking when it hits this limit.  Valid range is 10 to 12 hours.
#define UnderPoleLimit            12

// Minimum allowed declination, default = -91 (off)  Ignored on Alt/Azm mounts.
// For example, a value of +80 would stop gotos/tracking near the north celestial pole.
// For a Northern Hemisphere user, this would stop tracking when the mount is in the polar home position but
// that can be easily worked around by doing an alignment once and saving a park position (assuming a 
// fork/yolk mount with meridian flips turned off by setting the minutesPastMeridian values to cover the whole sky)
#define MinDec                   -91
// Maximum allowed declination, default =  91 (off)  Ignored on Alt/Azm mounts.
#define MaxDec                   +91

// Alt/Az mounts only. +/- maximum allowed Azimuth, default =  180.  Allowed range is 180 to 360
#define MaxAzm                   360

// Reverse the direction of movement.  Adjust as needed or reverse your wiring so things move in the right direction
// RA/Azm axis
#define AXIS1_REVERSE_OFF
// Dec/Alt axis
#define AXIS2_REVERSE_OFF

// Stepper driver Enable support, just wire Enable to Pins ? (Axis1) and ? (Axis2) and OnStep will pull these HIGH
// to disable the stepper drivers on startup and when Parked or Homed.  
// An Align, Sync, or Un-Park will enable the drivers.
// Adjust below if you need these pulled LOW to disable the drivers.
#define AXIS1_DISABLE HIGH
#define AXIS2_DISABLE HIGH

// For equatorial mounts, _ON powers down the Declination axis when it is not being used to help lower power use.
// During low rate guiding (<=1x) the axis stays enabled for 10 minutes after any guide on either axis.
// Otherwise, the Dec axis is disabled (powered off) 10 seconds after movement stops.
#define AXIS2_AUTO_POWER_DOWN_OFF

// Stepper driver Fault detection on Pins ? (Aux1) and ? (Aux2,) choose only one feature to use on Aux1/2.
// The SPI interface (on M0/M1/M2/Aux) can be used to detect errors on the TMC2130.
// other settings are LOW, HIGH, TMC2130 (if available applies internal pullup if LOW and pulldown if HIGH.)
#define AXIS1_FAULT_OFF
#define AXIS2_FAULT_OFF

// ------------------------------------------------------------------------------------------------------------
// THE FOLLOWING ARE INFREQUENTLY USED OPTIONS FOR THE MINIPCB SINCE USING ANY OF THESE WOULD REQUIRE SOLDERING
// TO THE PCB BACK AND ADDING OFF-PCB CIRCUITRY, MUCH EASIER TO USE A MAXPCB AND TEENSY3.5/3.6
// FOCUSER ROTATOR OR ALT/AZ DE-ROTATION
// ------------------------------------------------------------------------------------------------------------
// Pins ?,? = Step,Dir (choose either this option or the second focuser, not both)
// enable or disable rotator feature (for any mount type,) default=_OFF (de-rotator is available only for
// MOUNT_TYPE_ALTAZM.) [infrequently used option]
#define ROTATOR_OFF 

// this is the minimum number of milli-seconds between micro-steps, default=8
#define MaxRateAxis3               8
 // calculated as    :  stepper_steps * micro_steps * gear_reduction1 * (gear_reduction2/360)
// Rotator          :  24            * 8           * 20              *  6/360                = 64
// For de-rotation of Alt/Az mounts a quick estimate of the required resolution (in StepsPerDegree)
// would be an estimate of the circumference of the useful imaging circle in (pixels * 2)/360
#define StepsPerDegreeAxis3     64.0

// reverse the direction of Axis3 rotator movement
#define AXIS3_REVERSE_OFF 
// Pin ?.  Use HIGH for common stepper drivers if you want to power down the motor at stand-still.  Default _OFF.
#define AXIS3_DISABLE HIGH
// Power down the motor at stand-still? Use _ON if you want to power down.  Default _OFF.
#define AXIS3_AUTO_POWER_DOWN_OFF

// minimum allowed Axis3 rotator, default = -180
#define MinAxis3                -180
// maximum allowed Axis3 rotator, default =  180
#define MaxAxis3                 180

// FOCUSER1 -------------------------------------------------------------------------------------------------
// Pins ?,? = Step,Dir
// enable or disable focuser feature, default=_OFF
#define FOCUSER1_OFF

// this is the minimum number of milli-seconds between micro-steps, default=8
#define MaxRateAxis4               8

// figure this out by testing or other means
#define StepsPerMicrometerAxis4  0.5

// reverse the direction of Axis4 focuser movement
#define AXIS4_REVERSE_OFF

// Pin ?.  Use HIGH for common stepper drivers if you want to power down the motor at stand-still.
// Default _OFF.
#define AXIS4_DISABLE HIGH
// Power down the motor at stand-still? Use _ON if you want to power down.  Default _OFF.
#define AXIS4_AUTO_POWER_DOWN_OFF

// minimum allowed Axis4 position in millimeters, default = -25.0
#define MinAxis4                 -25.0

// maximum allowed Axis4 position in millimeters, default =  25.0
#define MaxAxis4                  25.0

// Enable DC focuser instead of a stepper motor.  Automatically uses Phase 1 if enabled.  Default _OFF.
#define AXIS4_DC_MODE_OFF

// FOCUSER2 -------------------------------------------------------------------------------------------------
// Pins ?,? = Step,Dir (choose either this option or the rotator, not both)
// enable or disable focuser feature, default=_OFF
#define FOCUSER2_OFF

// this is the minimum number of milli-seconds between micro-steps, default=8
#define MaxRateAxis5               8

// figure this out by testing or other means
#define StepsPerMicrometerAxis5  0.5

// reverse the direction of Axis5 focuser movement
#define AXIS5_REVERSE_OFF

// Pin ?.  Use HIGH for common stepper drivers if you want to power down the motor at stand-still.  Default _OFF.
#define AXIS5_DISABLE HIGH
// Power down the motor at stand-still? Use _ON if you want to power down.  Default _OFF.
#define AXIS5_AUTO_POWER_DOWN_OFF

// minimum allowed Axis5 position in millimeters, default = -25.0
#define MinAxis5               -25.0

// maximum allowed Axis5 position in millimeters, default =  25.0
#define MaxAxis5                25.0

// Enable DC focuser instead of a stepper motor.  Automatically uses Phase 1 if enabled.  Default _OFF.
#define AXIS5_DC_MODE_OFF

// ---------------------------------------------------------------------------------------------------------
#define FileVersionConfig 2

// Include the pins file
#include "src/pinmaps/Pins.Ramps14.h"
#endif

// === CONFIGURATION END
// This configuration was generated using the OnStep Configuration Generator
// On: 2019-07-21 04:07
