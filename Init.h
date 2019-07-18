#ifndef INIT_H_
#define INIT_H_
void Init(){


#define CoolerOC1A  OCR1A
#define OilOC1B   OCR1B
  
	/******************************************************************************
	*										ADC
	******************************************************************************/
	//ADCSRA=(1<<ADEN)|(1<<ADPS1)|(1<<ADPS0);
	//ADMUX=(0<<REFS1)|(1<<REFS0)|(0<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0);
	/******************************************************************************
	*										PORTS
	******************************************************************************/
	sbit(DDRB,1);	// Cooler
	sbit(DDRB,2);	// Engine
	
	cbit(PORTB,1);	// Cooler
	cbit(PORTB,2);	// Engine

	cbit(DDRC,3);	// jumper	as input - защита менюшки
	sbit(PORTC,3);	// jumper	pull up

	cbit(DDRC,2);	// alarm	as input - дискретный вход, аварийный
	sbit(PORTC,2);	// alarm	pull up

	cbit(PORTB,1);	// pull down Cooler
	cbit(PORTB,2);	// pull down Engine
	
	cbit(DDRB,3);	// button 0	as input
	cbit(DDRB,4);	// button 1	as input
	cbit(DDRB,5);	// button 2	as input

	sbit(PORTB,3);	// button 0 pull up
	sbit(PORTB,4);	// button 1 pull up
	sbit(PORTB,5);	// button 2 pull up
	/******************************************************************************
	*										TIMERS
	******************************************************************************/

	/******************************************************************************
	*										USARTOS :)
	******************************************************************************/
	/******************************************************************************
	*										xxx
	******************************************************************************/
}


// static uint8_t uint_to_BCD(uint8_t *uint){
// 	return ((*uint / 10) << 4) | (*uint % 10);
//}

#endif /* INIT_H_ */
