#include "PID.h"

byte customCharFlash[] = {
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

byte customCharGradus[] = {
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
  B00000
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

byte customCharArrow[] = {
  B00000,
  B00100,
  B00010,
  B11111,
  B00010,
  B00100,
  B00000,
  B00000
};
enum {
    FRAME_MAIN,
    FRAME_MENU
  };

uint8_t frameSelector = 0;

//char url[] = "https://github.com/adcNoise/ \0";

inline void lcdInit(void){
  lcd.begin(16, 2);
  
  lcd.createChar(0, customCharFlash);
  lcd.createChar(1, customCharQuad);
  lcd.createChar(2, customCharPumpA);
  lcd.createChar(3, customCharPumpB);
  lcd.createChar(4, customCharGradus);
  lcd.createChar(5, customCharArrow);

  /*while(*url){

     uint8_t i = 0;
     while(url[i]){
        url[i] = url[i+1];
        i++;}
     
      lcd.setCursor(0,1);
      lcd.print(url);
      delay(100);
    }//*/
  
  lcd.setCursor(0,0);
  lcd.print("//github.com");
  lcd.setCursor(0, 1);
  lcd.print("/adcNoise/");
  delay(2000);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("BABINGTON");
  lcd.setCursor(2, 1);
  lcd.print("EXPERIMENTAL! ");
  
  delay(500);    
  lcd.clear();
 }

 inline void mainFrame(){
   lcd.setCursor(0, 0);
    lcd.print("M:"); lcd.print((int8_t)CurrentOilTemperature);lcd.write((uint8_t)5);lcd.print((int8_t)TargetOilTemperature);lcd.write((uint8_t)4);lcd.print("C %");
        
    lcd.print((uint8_t)summary);lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.print("B:"); lcd.print((int8_t)CurrentAirTemperature);lcd.write((uint8_t)5);lcd.print((int8_t)TargetAirTemperature);lcd.write((uint8_t)4);lcd.print("C ");

//    if(PumpingFlag){
//      lcd.write((uint8_t)2);
//      PumpingFlag = false;}
//     else{
//      lcd.write((uint8_t)3);
//      PumpingFlag = true;}
    
    lcd.print(" ");
    
    if((vBurnerStatus==vBURNER_PHASE1_START)||(vBurnerStatus==vBURNER_PHASE3_START)||(vBurnerStatus==vBURNER_PHASE5_START)||(vBurnerStatus==vBURNER_PHASE7_START)||(vBurnerStatus==vBURNER_PHASE9_START)||(vBurnerStatus==vBURNER_PHASE11_START)){
      lcd.write((uint8_t)0);
    }else{
      lcd.print(" ");}
 }

 inline void menuFrame(){
  
  }
