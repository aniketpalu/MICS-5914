/*
 * MICS5914.c
 *
 *  Created on: Oct 1, 2020
 *      Author: Aniket Paluskar
 */

#include "MICS5914.h"

#include <ti/drivers/ADC.h>
#include <math.h>

/*
 * Static Functions
 */
static float getResistance(ADC_Handle adcHandle);


/*
 * Static Variables
 */
static uint16_t readings;

/**********************************************************
 * @fn               getNH3()
 *
 * @brief            Calculates the NH3 in the air
 *
 * @param            ADC_Handle
 *
 * @returns          uint16_t value of NH3 in ppm units
 */

uint16_t getNH3_MICS5914(ADC_Handle adcHandle)
{
    float NH3Detection_Volts = 0.0, NH3Detection = 0.0;
    NH3Detection_Volts = getResistance(adcHandle);
    NH3Detection = NH3Detection_Volts * (MAX_NH3_PPM / MAX_NH3_OP_VOLTAGE);
    return NH3Detection;
}


/**********************************************************
 * @fn               getResistance(ADC_Handle adc)
 *
 * @brief            Calculates the resistance of given Handle
 *
 * @param            ADC handle
 *
 * @returns          float value with unit Volts
 */
float getResistance(ADC_Handle adcHandle)
{
    uint32_t tempResistance=0;
    uint8_t count =0;
    int_fast16_t res;
    for(int i = 0;i < 100; i++)
    {
       res =  ADC_convert(adcHandle, &readings);
       if(res == ADC_STATUS_SUCCESS)
       {
          tempResistance = ADC_convertToMicroVolts(adcHandle, readings);
          tempResistance += tempResistance/pow(10,6);                      //Converting from MicroVolts to Volts
          count++;
       }
    }
    return count!=0 ? tempResistance/count: 0 ;
}
