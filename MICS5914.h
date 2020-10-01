/*
 * MICS5914.h
 *
 *  Created on: Oct 1, 2020
 *      Author: Aniket Paluskar
 */

#ifndef APPLICATION_MICS5914_MICS5914_H_
#define APPLICATION_MICS5914_MICS5914_H_

#include <ti/drivers/ADC.h>

/*************************************MACROS**************************************/
#define MAX_NH3_PPM         300             //Maximum NH3 Detection Level
#define MAX_NH3_OP_VOLTAGE  2.2             // Maximum Output Voltage from NH3 Sensor


/*
 * Functions
 */
uint16_t getNH3_MICS5914(ADC_Handle adcHandle);


#endif /* APPLICATION_MICS5914_MICS5914_H_ */