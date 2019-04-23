#include <LiquidCrystal.h>
#include "Predefined.h"
#include "Heater.h"
#include "lcd.h"

void setup() {
  lcdInit();
  delay(1000);  
  init();  
  lcd.clear();
}

unsigned long timingA;
unsigned long timingB;
unsigned long timingC;

void loop() {
  ////////////////////////////////////////////////////////////////////////////////
  if (millis() - timingA > 2000){ // 2s пауза Задача опроса температуры
    timingA = millis();
    sensors.requestTemperatures();
    CurrentOilTemperature = sensors.getTempCByIndex(0);
    CurrentAirTemperature = sensors.getTempCByIndex(1);
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
  }
}
