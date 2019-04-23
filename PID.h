#include "inttypes.h"

#define MAXINTEGRALOIL  20000
#define MININTEGRALOIL  -10000

uint8_t BurningFlag = 0;
uint8_t PumpingFlag = 0;
static float CurrentOilTemperature = 0;
static float CurrentAirTemperature = 0;
static float TargetOilTemperature = 65;

static float P_GAIN = 1;
static float I_GAIN = 0.001;
long integralSum;
float summary;    

inline void PID_OIL_HEATER(){
    static float ErrorOilTemperature;
    ErrorOilTemperature = TargetOilTemperature-CurrentOilTemperature;
    
    integralSum+=(long)ErrorOilTemperature;

    if(integralSum>MAXINTEGRALOIL)
      integralSum=MAXINTEGRALOIL;
    
    if(integralSum<MININTEGRALOIL)
      integralSum=MININTEGRALOIL;
    
    summary =   P_GAIN * ErrorOilTemperature;
    summary +=  I_GAIN * integralSum;//*/    
 }
