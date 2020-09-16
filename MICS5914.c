#include "MICS5914.h"


int _pinNo;
float tempResistance_NH3;
/************************************************************************
 * @fn          setup(pinNO);
 * 
 * @brief       Sets the Pin Mode and base resistance of NH3
 * 
 * @param       Pin number of Microcontroller connected to MICS5914
 * 
 * @return      None
 */

void setup(int pinNO)
{
    _pinNo = pinNO;
    pinMode(_pinNo, INPUT);
}



/************************************************************************
 * @fn          get_NH3_value();
 * 
 * @brief       Fetched the value from sensor
 * 
 * @param       None
 * 
 * @return      Float Value of NH3 in air, Unit : ppm
 */

float get_NH3_value()
{
    tempResistance_NH3 = 0;
    int i;
    for(i=0;i<100;i++)
    {
        tempResistance_NH3 += analogRead(_pinNo);
    }
    return tempResistance_NH3/100;
}