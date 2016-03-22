#ifndef _PERF_CONFIG_H_
#define _PERF_CONFIG_H_

/* Port Polarites */
#define DEFAULT_POLARITY Polar_ActiveLow

/* Port Configurations */
#define DEFAULT_IO_CONFIG IO_FAST_SLEW|IO_PULL_UP|IO_PULL_ENABLE|IO_DRIVE_4mA
#define KEYPAD_IN IO_FAST_SLEW|IO_PULL_DOWN|IO_PULL_ENABLE|IO_DRIVE_4mA

/* Pin definitions for Peripherals */
/********************************************************************************/

/* Stepper */
#define STEP_A { GPIO_E, io_PE, 0x1, DEFAULT_POLARITY }
#define STEP_B { GPIO_E, io_PE, 0x2, DEFAULT_POLARITY }
#define STEP_C { GPIO_E, io_PE, 0x4, DEFAULT_POLARITY }
#define STEP_D { GPIO_E, io_PE, 0x8, DEFAULT_POLARITY }

/* Servo */
	// This is the location of CCM3 output 
#define SERV_PWM { GPIO_D, io_PD7, 0x80, DEFAULT_POLARITY }

/* Encoder */
#define ENC_CS { GPIO_D, io_PD6, 0x40, DEFAULT_POLARITY }
#define ENC_CLK { GPIO_D, io_PD5, 0x20, DEFAULT_POLARITY }
#define ENC_DATA { GPIO_D, io_PD4, 0x10, DEFAULT_POLARITY }

/* Keypad */
#define KEY0 { GPIO_C, io_PC0, 0x1, DEFAULT_POLARITY }
#define KEY1 { GPIO_C, io_PC1, 0x2, DEFAULT_POLARITY }
#define KEY2 { GPIO_C, io_PC2, 0x4, DEFAULT_POLARITY }
#define KEY3 { GPIO_C, io_PC3, 0x8, DEFAULT_POLARITY }
#define KEY4 { GPIO_C, io_PC4, 0x10, DEFAULT_POLARITY }
#define KEY5 { GPIO_C, io_PC5, 0x20, DEFAULT_POLARITY }
#define KEY6 { GPIO_C, io_PC6, 0x40, DEFAULT_POLARITY }
#define KEY7 { GPIO_C, io_PC7, 0x80, DEFAULT_POLARITY }

/* LCD */
#define LCD_RS { GPIO_D, io_PD3, 0x8, DEFAULT_POLARITY }
#define LCD_RW { GPIO_D, io_PD2, 0x4, DEFAULT_POLARITY }
#define LCD_E { GPIO_D, io_PD1, 0x2, DEFAULT_POLARITY }
#define LCD_DB0 { GPIO_A, io_PA, 0x80, DEFAULT_POLARITY }
#define LCD_DB1 { GPIO_A, io_PA, 0x40, DEFAULT_POLARITY }
#define LCD_DB2 { GPIO_A, io_PA, 0x20, DEFAULT_POLARITY }
#define LCD_DB3 { GPIO_A, io_PA, 0x10, DEFAULT_POLARITY }
#define LCD_DB4 { GPIO_A, io_PA, 0x8, DEFAULT_POLARITY }
#define LCD_DB5 { GPIO_A, io_PA, 0x4, DEFAULT_POLARITY }
#define LCD_DB6 { GPIO_A, io_PA, 0x2, DEFAULT_POLARITY }
#define LCD_DB7 { GPIO_A, io_PA, 0x1, DEFAULT_POLARITY }

/* Peripheral Constants */
/********************************************************************************/

/* Stepper */
#define HIGH_SPEED_THRESH 50
#define MIN_STEP_TIME_16 33
#define MIN_STEP_TIME 2
#define DEFAULT_STEP_SPEED_16 128
#define STEP_SPEED_CURVE {0,0,1,3,4,7,9,12,15,19,22,27,31,36,41,46,51,57,63,69,75,81,87,93,100,106,112,118,124,130,136,142,148,153,158,163,168,172,177,180,184,187,190,192,195,196,198,199,199,200}

/* Servo */
	// Movement
#define MAX_SERVO_ANGLE 150
#define MAX_PULSE 6600
#define MIN_SERVO_ANGLE 30
#define MIN_PULSE 1550
#define TIME_FACTOR 42
#define TIME_FOR_20MS 61440
#define SERVO_TIMER_A_CFG TIMER_CLOCK_RATE_4|TIMER_MODE_UP

	// Feedback
#define SERVO_ADC_CFG ADC_CLK_RATE_DIV_2

/* Encoder */


/* Keypad */
#define KEYPAD_PRESSTHRESH 4
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define ZERO 0
#define UP 10
#define DOWN 11
#define SECOND 12
#define CLEAR 13
#define HELP 14
#define ENTER 15

/* LCD */
	// Initiate
#define INIT_LCD 0x38
	// Entry Mode
#define LCD_ENTRY_SET 0x004 // Default: |LCD_ENTRY_DEC|LCD_ENTRY_NOSH
#define LCD_ENTRY_INC 0x002
#define LCD_ENTRY_DEC 0x000
#define LCD_ENTRY_SH  0x001
#define LCD_ENTRY_NOSH 0x000 
	// Display Settings
#define LCD_DISPLAY_SET 0x008 // Default : |LCD_DISPLAY_OFF|LCD_DISPLAY_NOCURS|LCD_DISPLAY_NOBLNK
#define LCD_DISPLAY_ON 0x006
#define LCD_DISPLAY_OFF 0x000
#define LCD_DISPLAY_CURS 0x002
#define LCD_DISPLAY_NOCURS 0x000
#define LCD_DISPLAY_CBLNK 0x001
#define LCD_DISPLAY_NOCBLNK 0x000
	// Cursor/Display Shift
#define LCD_CURSSHIFTRIGHT 0x014
#define LCD_CURSSHIFTLEFT 0x010
#define LCD_DISPSHIFTLEFT 0x018
#define LCD_DISPSHIFTRIGHT 0x01C
	// R/W
#define LCD_WRITE 0x200
#define LCD_READ 0x300
	// Other Functions
#define LCD_RETURNHOME 0x002
#define LCD_CLEARSCREEN 0x001

#define LCD_GOTOADDRESS 0x080 // |ADDRESS
#define LCD_SECONDLINE 0x40

#define BUFFERLIMIT 40

#endif










