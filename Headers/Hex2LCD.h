/* Author: Group 11 - E&S
*
*/
#ifndef _HEX2LCD_H_
#define _HEX2LCD_H_

#include <IOConfig.h>
#include <Structs.h>
#include "time_funcs.h"
#include "PerfConfig.h"

/* Define Ports */
static const GlobalPin RS = LCD_RS;
static const GlobalPin RW = LCD_RW;
static const GlobalPin E_SIG = LCD_E;
static const GlobalPin DB0 = LCD_DB0;
static const GlobalPin DB1 = LCD_DB1;
static const GlobalPin DB2 = LCD_DB2;
static const GlobalPin DB3 = LCD_DB3;
static const GlobalPin DB4 = LCD_DB4;
static const GlobalPin DB5 = LCD_DB5;
static const GlobalPin DB6 = LCD_DB6;
static const GlobalPin DB7 = LCD_DB7;


static inline void WriteToLCD(int Data)
{
	io_set_config(DEFAULT_IO_CONFIG, RS.io_port);
	io_set_config(DEFAULT_IO_CONFIG, RW.io_port);
	io_set_config(DEFAULT_IO_CONFIG, E_SIG.io_port);
	io_set_config(DEFAULT_IO_CONFIG, DB0.io_port);
	io_set_config(DEFAULT_IO_CONFIG, DB1.io_port);
	io_set_config(DEFAULT_IO_CONFIG, DB2.io_port);
	io_set_config(DEFAULT_IO_CONFIG, DB3.io_port);
	io_set_config(DEFAULT_IO_CONFIG, DB4.io_port);
	io_set_config(DEFAULT_IO_CONFIG, DB5.io_port);
	io_set_config(DEFAULT_IO_CONFIG, DB6.io_port);
	io_set_config(KEYPAD_IN, DB7.io_port);
	
	globalPin_set_dir(PinDir_Output, &RS);
	globalPin_set_dir(PinDir_Output, &RW);
	globalPin_set_dir(PinDir_Output, &E_SIG);
	globalPin_set_dir(PinDir_Output, &DB0);
	globalPin_set_dir(PinDir_Output, &DB1);
	globalPin_set_dir(PinDir_Output, &DB2);
	globalPin_set_dir(PinDir_Output, &DB3);
	globalPin_set_dir(PinDir_Output, &DB4);
	globalPin_set_dir(PinDir_Output, &DB5);
	globalPin_set_dir(PinDir_Output, &DB6);
	globalPin_set_dir(PinDir_Input, &DB7);
	
	/* Define needed buffers, etc */
	int DataOut[] = {0,0,0,0,0,0,0,0,0,0};
	int Busy_Flag = 0;
	
	/* Load data out buffer */
	
	DataOut[0] = (Data >> (9)) & 0x001;
	DataOut[1] = (Data >> (8)) & 0x001;
	DataOut[9] = (Data >> (7)) & 0x001;
	DataOut[8] = (Data >> (6)) & 0x001;
	DataOut[7] = (Data >> (5)) & 0x001;
	DataOut[6] = (Data >> (4)) & 0x001;
	DataOut[5] = (Data >> (3)) & 0x001;
	DataOut[4] = (Data >> (2)) & 0x001;
	DataOut[3] = (Data >> (1)) & 0x001;
	DataOut[2] = Data & 0x001;
	
	globalPin_write(0, &RW);
	wait_ms(1);
	Busy_Flag = globalPin_read(&DB7);
	while (Busy_Flag != 1){
		Busy_Flag = globalPin_read(&DB7);
	}
	
	io_set_config(DEFAULT_IO_CONFIG, DB7.io_port);
	globalPin_set_dir(PinDir_Output, &DB7);
	
	globalPin_write(!DataOut[0], &RS);
	globalPin_write(!DataOut[1], &RW);
	globalPin_write(!DataOut[2], &DB0);
	globalPin_write(!DataOut[3], &DB1);
	globalPin_write(!DataOut[4], &DB2);
	globalPin_write(!DataOut[5], &DB3);
	globalPin_write(!DataOut[6], &DB4);
	globalPin_write(!DataOut[7], &DB5);
	globalPin_write(!DataOut[8], &DB6);
	globalPin_write(!DataOut[9], &DB7);
	
	globalPin_write(0, &E_SIG);
	globalPin_write(1, &E_SIG);
	
	globalPin_write(1, &RS);
	globalPin_write(0, &RW);
	globalPin_write(1, &DB0);
	globalPin_write(1, &DB1);
	globalPin_write(1, &DB2);
	globalPin_write(1, &DB3);
	globalPin_write(1, &DB4);
	globalPin_write(1, &DB5);
	globalPin_write(1, &DB6);
	globalPin_write(1, &DB7);
	
}

#endif