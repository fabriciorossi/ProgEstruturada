#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <gmp.h>

typedef struct {
    mpz_t numero; 
} BigNumber;

void criaBigNumber(BigNumber *num, int numero);

void criaBigNumberString(BigNumber *num, const char *str);

void printBigNumber(const BigNumber *num);

#endif
