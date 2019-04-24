#include "inttypes.h"

#define MAXINTEGRALOIL  200000
#define MININTEGRALOIL  -1000

static uint8_t BurningFlag = 0;
static uint8_t PumpingFlag = 0;
static float CurrentOilTemperature = 0;
static float CurrentAirTemperature = 0;
static float TargetOilTemperature = 65;

static float P_GAIN = 2;
static float I_GAIN = 0.005;
static long integralSum;
static float summary;

inline void CheckHeaterTemperature(){   // проверка температуры и если температура в норме разрешение включать горелку
    if((CurrentOilTemperature>=(TargetOilTemperature-3))&&(check())){
      sbit(PORTC,0);  // relay 1 ON
    }else{
      cbit(PORTC,0);  // relay 1 OFF
  }
}

inline void PID_OIL_HEATER(){
  if(check()){
    static float ErrorOilTemperature;
    ErrorOilTemperature = TargetOilTemperature-CurrentOilTemperature;

    if(summary<100) // для ограничения перегрева при достижении температуры. Можно удалить.
      integralSum+=(long)ErrorOilTemperature;

    if(integralSum>MAXINTEGRALOIL)
      integralSum=MAXINTEGRALOIL;
    
    if(integralSum<MININTEGRALOIL)
      integralSum=MININTEGRALOIL;
    
    summary =   P_GAIN * ErrorOilTemperature;
    summary +=  I_GAIN * integralSum;//*/

    if(summary<0)
      summary = 0;
    else if(summary>100)
      summary = 100;
  }else{
    integralSum = 0;
    summary = 0;
    }
}
