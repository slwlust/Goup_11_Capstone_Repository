/* Author: Group 11 - E&S
*
*/
#ifndef _SERVODRIVE_H_
#define _SERVODRIVE_H_

#include <IOConfig.h>
#include <Structs.h>
#include <Timer.h>
#include "PerfConfig.h"

/* Define Ports */
static const GlobalPin ServoData = SERV_PWM;

static inline void ServoMove(int Degree)
{
	
	int Position = Degree;
	if (Degree > MAX_SERVO_ANGLE) Position = MAX_SERVO_ANGLE;
	if (Degree < MIN_SERVO_ANGLE) Position = MIN_SERVO_ANGLE;
	Position = Position - 30;
	timer_set_config(SERVO_TIMER_A_CFG, TIMER_A);
	timer_set_config_ccm(TIMER_CCM_OUTPUT_OUT | TIMER_CCM_CAP_RISING | TIMER_CCM_COMP_NOT_CAP, 0, TIMER_A);
	timer_set_config_ccm(TIMER_CCM_OUTPUT_RESET_SET|TIMER_CCM_CAP_RISING|TIMER_CCM_COMP_NOT_CAP|TIMER_CCM_OUT_ENABLE, 3, TIMER_A);
	timer_write_CCR(TIME_FOR_20MS, 0, TIMER_A);
	timer_write_CCR(MIN_PULSE + TIME_FACTOR*Position,3, TIMER_A);
	timer_set_config(SERVO_TIMER_A_CFG|TIMER_ENABLE, TIMER_A);
	}
#endif