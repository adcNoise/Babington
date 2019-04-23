#include "PID.h"

byte customCharFlash[] = { // ������
  B00011,
  B00110,
  B01100,
  B11111,
  B00011,
  B10110,
  B11100,
  B11110
};

byte customCharQuad[] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111
};

byte customCharPumpA[] = {
  B00000,
  B10000,
  B11000,
  B11111,
  B00011,
  B00001,
  B00000,
  B00000
};
byte customCharPumpB[] = {
  B00111,
  B00110,
  B00100,
  B00100,
  B01100,
  B11100,
  B00000,
  B00000
};
enum {
    FRAME_MENU,
    FRAME_MAIN
  };

uint8_t frameSelector = 0;

inline void lcdInit(void){
  lcd.begin(16, 2);
  lcd.createChar(0, customCharFlash);
  lcd.createChar(1, customCharQuad);
  lcd.createChar(2, customCharPumpA);
  lcd.createChar(3, customCharPumpB);
  lcd.setCursor(4, 0);
  lcd.print("BABINGTON");
  lcd.setCursor(2, 1);
  lcd.print("EXPERIMENTAL!");
 }

 inline void mainFrame(){
   lcd.setCursor(0, 0);
    lcd.print("M:"); lcd.print(CurrentOilTemperature);lcd.print("  ");

    if(BurningFlag){
      lcd.write((uint8_t)0);
      BurningFlag = false;}
     else{
      lcd.print(" ");
      BurningFlag = true;}

    lcd.setCursor(0, 1);
    lcd.print("B:"); lcd.print(CurrentAirTemperature);lcd.print("  ");

    if(PumpingFlag){
      lcd.write((uint8_t)2);
      PumpingFlag = false;}
     else{
      lcd.write((uint8_t)3);
      PumpingFlag = true;}
 }

 inline void menuFrame(){
    
  }
