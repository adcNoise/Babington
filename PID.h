#include "inttypes.h"

#define MAXINTEGRALOIL  200
#define MININTEGRALOIL -200

uint8_t BurningFlag = 0;
uint8_t PumpingFlag = 0;
static float CurrentOilTemperature = 0;
static float CurrentAirTemperature = 0;
static float TargetOilTemperature = 40;
static float ErrorOilTemperature = 0;

static float P_GAIN = 1;
static float I_GAIN = 1;
long integralSum;


inline float PID_OIL_HEATER(){
    float summary;
    
    ErrorOilTemperature = TargetOilTemperature-CurrentOilTemperature;
    
    integralSum+=(long)ErrorOilTemperature;

    if(integralSum>MAXINTEGRALOIL)
      integralSum=MAXINTEGRALOIL;
    
    if(integralSum<MININTEGRALOIL)
      integralSum=MININTEGRALOIL;
    
    summary =   P_GAIN * ErrorOilTemperature;
    summary +=  I_GAIN * integralSum;
    
  }
