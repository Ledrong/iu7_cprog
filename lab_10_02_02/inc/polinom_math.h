#ifndef POLINOM_MATH_H
#define POLINOM_MATH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cdio.h"

int val(polinom_t *polinom, int count, int *val_result);
void sum(polinom_t *polinom, polinom_t *polinom_second, int count, int count_second);
void ddx(polinom_t *polinom, int count);
void dvd(polinom_t *polinom, int count);

#endif
