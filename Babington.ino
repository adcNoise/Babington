#include <LiquidCrystal.h>
#include "Predefined.h"
#include "Heater.h"
#include "lcd.h"

void setup() {
  lcdInit();
  init();
}

unsigned long timingA;
unsigned long timingB;
unsigned long timingC;
int8_t  temp = 0; /// debug variable!!!!!!!!!!!!!

void loop() {
  ////////////////////////////////////////////////////////////////////////////////
  if (millis() - timingA > 2000){ // 2s пауза Задача опроса температуры
    timingA = millis();
    sensors.requestTemperatures();
    CurrentOilTemperature = sensors.getTempCByIndex(0);
    CurrentAirTemperature = sensors.getTempCByIndex(1);
    
    CurrentOilTemperature+=temp;
 }
 ////////////////////////////////////////////////////////////////////////////////
  if (millis() - timingB > 200){ // 0.2s пауза
    timingB = millis();

    switch(frameSelector){
    case FRAME_MAIN: // отображение окна индикации
      mainFrame();  
      break;
    case FRAME_MENU:
      menuFrame();  // отображение окна меню
      break;}
 }
 ////////////////////////////////////////////////////////////////////////////////
  if (millis() - timingC > 500){ // 0.5s пауза
    timingC = millis();
    PID_OIL_HEATER();

    if(CurrentOilTemperature>=(TargetOilTemperature-3))
      sbit(PORTC,0);  // relay 1
    else
      cbit(PORTC,0); 
        
    if(!(CHECKBIT(PINB,4))) /// debug variable!!!!!!!!!!!!!
      temp++;
    
    if(!(CHECKBIT(PINB,5))) /// debug variable!!!!!!!!!!!!!
      temp--;    
  }
}
