/**
 * @file arrays.c
 * @brief Datoteka koja definise funkcije za upravljanje nizovima
 * @author Jana Jankovic
 * @date 16-5-2021
 * @version 1.0
 */

#include "arrays.h"

int16_t Element(int16_t first_element, int16_t difference, int16_t n)
{
    int16_t n_element;
    n_element = first_element + ((n-1) * difference);
	return n_element;
}

int16_t Sum(int16_t first_element, int16_t difference, int16_t n, int8_t mode)
{
	int16_t suma=0;
	if (mode == ITERATIVE)
	{
		for (int8_t i = 0; i < n; i++)
			suma += Element(first_element, difference, i);
	}

	if (mode == FORMULA)
	{
	    suma = (n/2)*(first_element + Element(first_element, difference, n));
	}

	return suma;

}



