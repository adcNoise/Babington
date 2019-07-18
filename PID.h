#include "inttypes.h"

#define MAXINTEGRALOIL  200000
#define MININTEGRALOIL  -10000

static float CurrentOilTemperature = 0;
static float CurrentAirTemperature = 0;
static float TargetOilTemperature = 60;
static float TargetAirTemperature = 22;

static float P_GAIN = 2;
static float I_GAIN = 0.01;
static long integralSum;
static float summary;

inline void CheckHeaterTemperature(){   // проверка температуры и если температура в норме разрешение включать горелку
    if((CurrentOilTemperature>=(TargetOilTemperature-3))&&(check())){
        if(vBurnerStatus==vBURNER_PHASE0_COLD)
          vBurnerStatus = vBURNER_PHASE1_START;
      return 1;
    }else{
      vBurnerStatus = vBURNER_PHASE0_COLD;
      return 0;
  }
}

inline void PID_OIL_HEATER(){
  if(check()){
    static float ErrorOilTemperature;
    ErrorOilTemperature = TargetOilTemperature-CurrentOilTemperature;

    if(summary<255) // для ограничения перегрева при достижении температуры. Можно удалить.
      integralSum+=(long)ErrorOilTemperature;

    if(integralSum>MAXINTEGRALOIL)
      integralSum=MAXINTEGRALOIL;
    
    if(integralSum<MININTEGRALOIL)
      integralSum=MININTEGRALOIL;
    
    summary =   P_GAIN * ErrorOilTemperature;
    summary +=  I_GAIN * integralSum;//*/

    if(summary<0)
      summary = 0;
    else if(summary>255)
      summary = 255;
  }else{
    integralSum = 0;
    summary = 0;
    }
}
