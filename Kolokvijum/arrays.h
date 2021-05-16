/**
 * @file arrays.h
 * @brief Datoteka koja deklarise funkcije za upravljanje nizovima
 * @author Jana Jankovic
 * @date 16-5-2021
 * @version 1.0
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_

#include <stdint.h>

/// Makro za podesavanje nacina racunanja sume u iterative
#define ITERATIVE 1
/// Makro za podesavanje nacina racunanja sume formula
#define FORMULA 2

/**
 * Element - izra�unava vrednost n-tog �lana aritmeti�kog niza opisanog pomo�u po�etne vrednosti niza i razlike
 * @param first_element - ulaz tipa int16_t - pocetna vrednost niza
 * @param difference - ulaz tipa int16_t - razlika
 * @param n - ulaz tipa int16_t - redni broj clana niza
 * @return Vrednost n-tog clana aritmeti�kog niza
 */
int16_t Element(int16_t first_element, int16_t difference, int16_t n);


/**
 * Sum - izra�unava sumu prvih n �lanova aritmeti�kog niza opisanog pomo�u po�etne vrednosti niza i razlike, na osnovu parametra mode
 * @param first_element - ulaz tipa int16_t - pocetna vrednost niza
 * @param difference - ulaz tipa int16_t - razlika
 * @param n - ulaz tipa int16_t - redni broj clana niza
 * @param mode - ulaz tipa int16_t - nacin izracunavanja sume
 * @return Vrednost sume prvih n clanova aritmetickog niza
 */
int16_t Sum(int16_t first_element, int16_t difference, int16_t n, int8_t mode);



#endif /* ARRAYS_H_ */
