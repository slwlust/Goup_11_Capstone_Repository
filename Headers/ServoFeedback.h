/* ServoFeedback Function Set 
* Author: Spencer Lust
*/

#ifndef _SERVOFEEDBACK_H_
#define _SERVOFEEDBACK_H_

#include <ADC.h>
#include "PerfConfig.h"

/* Setp up feedback ADC */
static inline void init_ServoFeedback(void){
	ADC_set_config(SERVO_ADC_CFG);
	ADC_power_on();
}

/* ADC read and conversion to angle */
static inline int ServoGetPos(void){
	ADC_start();
	int ADCReg;
	
	// collect ADC data until correct data is set
	while ((ADCReg & ADC_BUSY_BIT) != 0){
		ADCReg = ADC_read();
	}
	
	// Convert from the ADC output to the servo angle
	ADCReg = ADCReg & kADCReadDataMask;
	
}








#endif