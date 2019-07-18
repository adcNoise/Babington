#ifndef PREDEFINED_H_
#define PREDEFINED_H_

#define BURNING_ON  true
#define BURNING_OFF false

/// Макросы циклических сдвигов
#define ROL(x) ((x << 1) | (x >> 7))
#define ROR(x) ((x >> 1) | (x << 7))

#define bauddivider(x) (XTAL/(16*x)-1) // рассчёт предделителя
#define HI(x) ((x)>>8)
#define LO(x) ((x)& 0xFF)

/// макросы работы с портамии
#define sbit(reg,bit)	reg |= (1<<bit)			// Macro defined for Setting a bit of any register.
#define cbit(reg,bit)	reg &= ~(1<<bit)		// Macro defined for Clearing a bit of any register.
#define chbit(reg,bit)	reg ^= (1<<bit)			// 

#define PortReg(port) (*(port))
#define DirReg(port) (*((port) - 1))
#define PinReg(port) (*((port) - 2))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

#define nop()	asm volatile("nop")

#define BAUDRATE 9600L 

#define RELAY1_ON	  sbit(PORTC,1);
#define RELAY1_OFF	cbit(PORTC,1);
#define RELAY1_CH   chbit(PORTC,1);

#define RELAY2_ON	  sbit(PORTC,0);
#define RELAY2_OFF	cbit(PORTC,0);

#endif /* PREDEFINED_H_ */
