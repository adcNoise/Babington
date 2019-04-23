#include "inttypes.h"

uint8_t BurningFlag = 0;
uint8_t PumpingFlag = 0;
static float CurrentOilTemperature = 0;
static float CurrentAirTemperature = 0;
static float TargetOilTemperature = 40;
static float ErrorOilTemperature = 0;

inline float PID_OIL_HEATER(){
    ErrorOilTemperature = TargetOilTemperature-CurrentOilTemperature;
    
  }
