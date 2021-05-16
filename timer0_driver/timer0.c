/**
 * @file timer0.c
 * @brief Datoteka koja definise funkcije za upravljanje tajmerom 0
 * @author Ime Prezime
 * @date 23-3-2021
 * @version 1.0
 */
#include "timer0.h"

/// Promenljiva koja skladisti broj milisekundi proteklih od pokretanja aplikacije
volatile uint32_t ms = 0;



void timer0DelayMs(uint32_t delay_length)
{
    uint32_t t0 = timer0millis();
    while(timer0millis() - t0 < delay_length);
}

/******************************************************************************************/

void timer0InteruptInit()
{
    // Inicijalizacija tajmera 0 tako da perioda prekida bude 1ms
    TCCR0A = 0x02;
    TCCR0B = 0x03;
    OCR0A = 249;
    TIMSK0 = 0x02;

    // Podesavanje globalne dozvole prekida
    sei();
}

/******************************************************************************************/

/**
 * ISR - prekidna rutina tajmera 0 u modu CTC
 */
ISR(TIMER0_COMPA_vect)
{
    // Inkrementovanje broja milisekundi koje su prosle od pokretanja aplikacije
    ms++;
}

/******************************************************************************************/

uint32_t timer0millis()
{
    uint32_t tmp;
    cli(); // Zabrana prekida
    tmp = ms; // Ocitavanje vremena
    sei(); // Dozvola prekida
    return tmp;
}
