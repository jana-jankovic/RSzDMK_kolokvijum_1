/**
 * @file arrays.c
 * @brief Aplikacija za rad sa nizovima
 * @author Jana Jankovic
 * @date 16-5-2021
 * @version 1.0
 */

#include <stdint.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "../usart_driver/usart.h"
#include "../pin_driver/pin.h"
#include "../timer0_driver/timer0.h"

const int8_t decimal_digits[] = {
   '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

int16_t pretvori(int8_t s)
{
	int8_t br=0;
	for(int16_t i=0; i <= 9; i++)
	{
		if( s == decimal_digits[i] ) {
			br = i;}
	}
	return br;
}

int16_t stepen(int8_t s)
{
	int16_t br=1;
	for(int8_t i=0; i < s; i++)
	{
		br *= 10;
	}
	return br;
}


int main()
{
	usartInit(9600);

	int8_t izlaz1[64]="Unesite prvi element:\r\n";
	int8_t izlaz2[64]="Unesite razliku:\r\n";
	int8_t izlaz3[64]="Unesite redni broj:\r\n";

	int16_t prvi[64];
	int16_t razlika[64];
	int16_t broj[64];

	int16_t izlaz4[64];
	int16_t izlaz5[64];
	int16_t izlaz6[64];
	int16_t izlaz7[64];

	while(1)
	{
		pinInit(PORT_B, 5, OUTPUT);

	    usartPutString(izlaz1);

	    pinSetValue(PORT_B, 5, HIGH);

	    while(usartAvailable() == 0);
	    _delay_ms(500);

	    pinSetValue(PORT_B, 5, LOW);

	    int8_t duzina_prvog = usartAvailable();

	   	usartGetString(prvi);

	   	int16_t prvi_clan=0;

	   	for(int8_t i =0; i<duzina_prvog; i++)
		{
			prvi_clan += ((pretvori(prvi[i])) * stepen(duzina_prvog -1 - i));

		}

	   	usartPutString(izlaz2);

		while(usartAvailable() == 0);
		_delay_ms(500);

		int8_t duzina_razlike = usartAvailable();

		usartGetString(razlika);

		int16_t diff=0;

		for(int8_t i =0; i<duzina_razlike; i++)
		{
			diff += ((pretvori(razlika[i])) * stepen(duzina_razlike -1 - i));

		}

	   	usartPutString(izlaz3);

		while(usartAvailable() == 0);
		_delay_ms(500);

		int8_t duzina_broja = usartAvailable();

		usartGetString(broj);

		int16_t n=0;

		for(int8_t i =0; i<duzina_broja; i++)
		{
			n += ((pretvori(broj[i])) * stepen(duzina_broja -1 - i));

		}

		timer0InteruptInit();

		int16_t el = Element(prvi_clan, diff, n);

		int16_t vr1 = timer0millis();


		int16_t sum_i = Sum(prvi_clan, diff, n, "ITERATIVE");

		int16_t vr2 = timer0millis();


		int16_t sum_f = Sum(prvi_clan, diff, n, "FORMULA");

		int16_t vr3 = timer0millis();

		int16_t vr4 = vr2- vr1;
		int16_t vr5 = vr3- vr2;

		sprintf(izlaz4,"Prvi element niza: %d, razlika: %d, n: %d \r\n", prvi_clan, diff, n);
		sprintf(izlaz5,"n-ti_element: %d, proteklo vreme: %dms\r\n", el, vr1);
		sprintf(izlaz6,"suma_iter: %d, proteklo vreme: %dms\r\n", sum_i, vr4);
		sprintf(izlaz7,"suma_form: %d, proteklo vreme: %dms\r\n", sum_i, vr5);

		usartPutString(izlaz4);
		usartPutString(izlaz5);
		usartPutString(izlaz6);
		usartPutString(izlaz7);



	}
	return 0;
}




