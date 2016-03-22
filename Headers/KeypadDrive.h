/* Author: Group 11 - E&S
*
*/
/* A program to test for proper pin configurations */
#ifndef _KEYPADDRIVE_H_
#define _KEYPAD_H_

#include <IOConfig.h>
#include <Structs.h>

#include "PerfConfig.h"

static const GlobalPin row1 = KEY0;
static const GlobalPin row2 = KEY1;
static const GlobalPin row3 = KEY2;
static const GlobalPin row4 = KEY3;
static const GlobalPin col1 = KEY4;
static const GlobalPin col2 = KEY5;
static const GlobalPin col3 = KEY6;
static const GlobalPin col4 = KEY7;

static inline uint16_t getKeyPress(void)
{
	
	enum PinLogicState ONHIGH = OFF;
	enum PinLogicState OFFLOW = ON;
	io_set_config(DEFAULT_IO_CONFIG, row1.io_port);
	io_set_config(DEFAULT_IO_CONFIG, row2.io_port);
	io_set_config(DEFAULT_IO_CONFIG, row3.io_port);
	io_set_config(DEFAULT_IO_CONFIG, row4.io_port);
	io_set_config(KEYPAD_IN, col1.io_port);
	io_set_config(KEYPAD_IN, col2.io_port);
	io_set_config(KEYPAD_IN, col3.io_port);
	io_set_config(KEYPAD_IN, col4.io_port);
	
	globalPin_set_dir(PinDir_Output, &row1);
	globalPin_set_dir(PinDir_Output, &row2);
	globalPin_set_dir(PinDir_Output, &row3);
	globalPin_set_dir(PinDir_Output, &row4);
	globalPin_set_dir(PinDir_Input, &col1);
	globalPin_set_dir(PinDir_Input, &col2);
	globalPin_set_dir(PinDir_Input, &col3);
	globalPin_set_dir(PinDir_Input, &col4);
	
{
	int count = 0;
	int key = 0;
	
	while (count != KEYPAD_PRESSTHRESH)
	{
		int i = 0;
		while (i == 0){
			
			//row 1
			globalPin_write(ONHIGH, &row1);
			if (globalPin_read(&col1)== ONHIGH)
			{
				i = ONE;
				globalPin_write(OFFLOW, &row1);
				break;
			}
			if (globalPin_read(&col2)== ONHIGH)
			{
				i = TWO;
				globalPin_write(OFFLOW, &row1);
				break;
			}
			if (globalPin_read(&col3)== ONHIGH)
			{
				i = THREE;
				globalPin_write(OFFLOW, &row1);
				break;
			}
			if (globalPin_read(&col4)== ONHIGH)
			{
				i = UP;
				globalPin_write(OFFLOW, &row1);
				break;
			}
			globalPin_write(OFFLOW, &row1);
			
			//row2
			globalPin_write(ONHIGH, &row2);
			if (globalPin_read(&col1)== ONHIGH)
			{
				i = FOUR;
				globalPin_write(OFFLOW, &row2);
				break;
			}
			if (globalPin_read(&col2)== ONHIGH)
			{
				i = FIVE;
				globalPin_write(OFFLOW, &row2);
				break;
			}
			if (globalPin_read(&col3)== ONHIGH)
			{
				i = SIX;
				globalPin_write(OFFLOW, &row2);
				break;
			}
			if (globalPin_read(&col4)== ONHIGH)
			{
				i = DOWN;
				globalPin_write(OFFLOW, &row2);
				break;
			}
			globalPin_write(OFFLOW, &row2);
			
			//row 3
			globalPin_write(ONHIGH, &row3);
			if (globalPin_read(&col1)== ONHIGH)
			{
				i = SEVEN;
				globalPin_write(OFFLOW, &row3);
				break;
			}
			if (globalPin_read(&col2)== ONHIGH)
			{
				i = EIGHT;
				globalPin_write(OFFLOW, &row3);
				break;
			}
			if (globalPin_read(&col3)== ONHIGH)
			{
				i = NINE;
				globalPin_write(OFFLOW, &row3);
				break;
			}
			if (globalPin_read(&col4)== ONHIGH)
			{
				i = SECOND;
				globalPin_write(OFFLOW, &row3);
				break;
			}
			globalPin_write(OFFLOW, &row3);
			
			//row4
			globalPin_write(ONHIGH, &row4);
			if (globalPin_read(&col1)== ONHIGH)
			{
				i = CLEAR;
				globalPin_write(OFFLOW, &row4);	
				break;
			}
			if (globalPin_read(&col2)== ONHIGH)
			{
				i = ZERO;
				globalPin_write(OFFLOW, &row4);	
				break;
			}
			if (globalPin_read(&col3)== ONHIGH)
			{
				i = HELP;
				globalPin_write(OFFLOW, &row4);	
				break;
			}
			if (globalPin_read(&col4)== ONHIGH)
			{
				i = ENTER;
				globalPin_write(OFFLOW, &row4);	
				break;
			}
			globalPin_write(OFFLOW, &row4);	
		}
		if (i == key)
			count++;
		else{
			key = i;
			count = 0;
		}
			
	}
	
	
	
	return key;
}
}

#endif