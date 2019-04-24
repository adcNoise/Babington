#include "DallasTemperature.h"
#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

enum{
  vHe_STOPED,
  vHe_ALARMED,
  vHe_RUNING,
  vHe_STARTING
  };
  
uint8_t HeaterStatus = vHe_STOPED;

inline uint8_t check(){
    
    
    return 1;
  }

inline void init(){
  // НАСТРОЙКА ДИСКРЕТНЫХ ВЫХОДОВ
  sbit(DDRC,1); // выход дискретной аварии
  cbit(PORTC,1);  // выход дискретной аварии

  sbit(DDRC,0); // relay 1
  cbit(PORTC,0);  // relay 1
  // НАСТРОЙКА ЛИНИИ ONEWIRE
   sensors.begin();
  }
