/* Author: Group 11 - E&S
*
*/
/* A program to test for proper pin configurations */
#ifndef _STEPPERDRIVER_H_
#define _STEPPERDRIVER_H_

#include <IOConfig.h>
#include <Structs.h>

#include "PerfConfig.h"
#include "time_funcs.h"

/* Define Ports */
static const GlobalPin A_step = STEP_A;
static const GlobalPin B_step = STEP_B;
static const GlobalPin C_step = STEP_C;
static const GlobalPin D_step = STEP_D;

/* Define Variables*/

enum Rotation {
	Clockwise = 0,
	CounterClockwise = 1};
const int Step_Curve[] = STEP_SPEED_CURVE;


static inline void StepperRot(enum Rotation direction, int steps ){
	init_clock();
	/* Redefine output states (for proper output) */
	enum PinLogicState OUTHIGH = OFF;
	enum PinLogicState OUTLOW = ON;
	
	
	/* Define running variables */
	int state  = 0;
	int count = 0;
	int step_speed_adj = 0;
	int speed_up_steps = 0, speed_down_steps = 0;
	int step_speed = 0;
	
	/* Initialize clock for timers */
	/* Set pin configurations and directions */
	io_set_config(DEFAULT_IO_CONFIG, A_step.io_port);
	io_set_config(DEFAULT_IO_CONFIG, B_step.io_port);
	io_set_config(DEFAULT_IO_CONFIG, C_step.io_port);
	io_set_config(DEFAULT_IO_CONFIG, D_step.io_port);
	
	globalPin_set_dir(PinDir_Output, &A_step);
	globalPin_set_dir(PinDir_Output, &B_step);
	globalPin_set_dir(PinDir_Output, &C_step);
	globalPin_set_dir(PinDir_Output, &D_step);	
	

	
	/* If moving more than 90 degrees */
	 if (steps >= HIGH_SPEED_THRESH)
	{
		 /* Define speed up and slow down length */
		 if (steps >= (HIGH_SPEED_THRESH+HIGH_SPEED_THRESH))
		 {
			 speed_up_steps = HIGH_SPEED_THRESH;
			 speed_down_steps = steps - HIGH_SPEED_THRESH;
			 step_speed = MIN_STEP_TIME_16;
		 }
		 else{
			speed_up_steps = ( steps/2 );
			speed_down_steps = steps -( steps/2 );
			step_speed = DEFAULT_STEP_SPEED_16;
		}
		
	}
	
	/* If moving less than 90 degrees */
	else {
		step_speed = DEFAULT_STEP_SPEED_16;
	}
	/* Run stepper based on number of steps required */
		while (count != steps){
			if (count <= speed_up_steps)
				step_speed_adj = Step_Curve[speed_up_steps-count];
			else if (count >= speed_down_steps)
				step_speed_adj = Step_Curve[count - speed_down_steps];
			else
				step_speed_adj = 0;
			switch (state){
				case 0:
				globalPin_write(OUTLOW, &A_step);
				globalPin_write(OUTLOW, &B_step);
				globalPin_write(OUTHIGH, &C_step);
				globalPin_write(OUTHIGH, &D_step);
				wait_16th_ms(step_speed+step_speed_adj);
				break;
				case 1:
				globalPin_write(OUTHIGH, &A_step);
				globalPin_write(OUTLOW, &B_step);
				globalPin_write(OUTLOW, &C_step);
				globalPin_write(OUTHIGH, &D_step);
				wait_16th_ms(step_speed+step_speed_adj);
				break;
				case 2:
				globalPin_write(OUTHIGH, &A_step);
				globalPin_write(OUTHIGH, &B_step);
				globalPin_write(OUTLOW, &C_step);
				globalPin_write(OUTLOW, &D_step);
				wait_16th_ms(step_speed+step_speed_adj);
				break;
				case 3:
				globalPin_write(OUTLOW, &A_step);
				globalPin_write(OUTHIGH, &B_step);
				globalPin_write(OUTHIGH, &C_step);
				globalPin_write(OUTLOW, &D_step);
				wait_16th_ms(step_speed+step_speed_adj);
				break;
			}
			if (direction == Clockwise)
			{
				int old =state;
				state = (old+1) % 4;
			}
			else
			{
				if (state  == 0)
					state = 3;
				else
					state--;
			}
			count++;
			
		}
		
		globalPin_write(OUTLOW, &A_step);
		wait_ms(1);
		globalPin_write(OUTLOW, &B_step);
		wait_ms(1);
		globalPin_write(OUTLOW, &C_step);
		wait_ms(1);
		globalPin_write(OUTLOW, &D_step);
		wait_ms(1);
	
}
#endif
