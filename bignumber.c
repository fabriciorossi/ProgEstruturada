#include "bignumber.h"

void criaBigNumber(BigNumber *num, int numero) {
    mpz_init_set_si(num->numero, numero);
}

void criaBigNumberString(BigNumber *num, const char *str) {
    mpz_init_set_str(num->numero, str, 10);
}

void printBigNumber(const BigNumber *num) {
    gmp_printf("%Zd\n", num->numero);
}
