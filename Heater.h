#include "DallasTemperature.h"
#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


inline void init(){
  // НАСТРОЙКА ДИСКРЕТНЫХ ВЫХОДОВ
  
  // НАСТРОЙКА ЛИНИИ ONEWIRE
   sensors.begin();
  }
