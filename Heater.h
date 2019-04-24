#include "DallasTemperature.h"
#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

enum {
  vHe_STOPED,
  vHe_ALARMED,
  vHe_RUNING,
  vHe_STARTING
};

enum {
  vBURNER_PHASE0_COLD,        // Горелка холодная, запуска поджиг нет смысла
  vBURNER_PHASE1_START,       // Старт поджига, в это время происходит электроподжиг
  vBURNER_PHASE2_PAUSED,      // Пауза цикла
  vBURNER_PHASE3_START,       // Старт поджига, в это время происходит электроподжиг
  vBURNER_PHASE4_PAUSED,      // Пауза
  vBURNER_PHASE5_START,       // Старт поджига, в это время происходит электроподжиг
  vBURNER_PHASE6_PAUSED,      // Пауза
  vBURNER_PHASE7_START,       // Старт поджига, в это время происходит электроподжиг
  vBURNER_PHASE8_PAUSED,      // Пауза
  vBURNER_PHASE9_START,       // Старт поджига, в это время происходит электроподжиг
  vBURNER_PHASE10_PAUSED,    // Пауза
  vBURNER_PHASE11_START,      // Старт поджига, в это время происходит электроподжиг
  vBURNER_PHASE12_STOPED      // Поджиг неудачен или завершён
};

uint8_t vBurnerStatus = vBURNER_PHASE0_COLD;

uint8_t HeaterStatus = vHe_STOPED;

uint8_t check() {

  return 1;
}

inline void BurningFunctions() {
  switch (vBurnerStatus) {
    case  vBURNER_PHASE0_COLD:      // Горелка холодная, запуска поджиг нет смысла
    break;
    case  vBURNER_PHASE1_START:     // Старт поджига, в это время происходит электроподжиг
    vBurnerStatus++;
    break;
    case  vBURNER_PHASE2_PAUSED:    // Пауза цикла
    vBurnerStatus++;
    break;
    case  vBURNER_PHASE3_START:     // Старт поджига, в это время происходит электроподжиг
    vBurnerStatus++;
    break;
    case  vBURNER_PHASE4_PAUSED:    // Пауза
    vBurnerStatus++;
    break;
    case  vBURNER_PHASE5_START:     // Старт поджига, в это время происходит электроподжиг
    vBurnerStatus++;
    break;
    case  vBURNER_PHASE6_PAUSED:    // Пауза
    vBurnerStatus++;
    break;
    case  vBURNER_PHASE7_START:     // Старт поджига, в это время происходит электроподжиг
    vBurnerStatus++;
    break;
    case  vBURNER_PHASE8_PAUSED:    // Пауза
    vBurnerStatus++;
    break;
    case  vBURNER_PHASE9_START:     // Старт поджига, в это время происходит электроподжиг
    vBurnerStatus++;
    break;
    case  vBURNER_PHASE10_PAUSED:   // Пауза
    vBurnerStatus++;
    break;
    case  vBURNER_PHASE11_START:    // Старт поджига, в это время происходит электроподжиг
    vBurnerStatus++;
    break;
    case  vBURNER_PHASE12_STOPED:   // Поджиг неудачен или завершён
    break;
    default: break;
  }
}

inline void init() {
  // НАСТРОЙКА ДИСКРЕТНЫХ ВЫХОДОВ
  sbit(DDRC, 1); // выход дискретной аварии
  cbit(PORTC, 1); // выход дискретной аварии

  sbit(DDRC, 0); // relay 1
  cbit(PORTC, 0); // relay 1
  // НАСТРОЙКА ЛИНИИ ONEWIRE
  sensors.begin();
}
