#include <stdio.h>
#include <stdlib.h>
#include "bignumber.h"

int main() {
    BigNumber a, b, resultado;
    char operador;
    char buffer_a[70], buffer_b[70]; 

    criaBigNumber(&a, 0);
    criaBigNumber(&b, 0);
    criaBigNumber(&resultado, 0);

    BigNumber *resultados = NULL;
    size_t tamanhoNumero = 0;

    while (scanf("%s %s", buffer_a, buffer_b) == 2) {
        scanf(" %c", &operador);

        criaBigNumberString(&a, buffer_a);
        criaBigNumberString(&b, buffer_b);

        switch (operador) {
            case '+':
                mpz_add(resultado.numero, a.numero, b.numero);
                break;
            case '-':
                mpz_sub(resultado.numero, a.numero, b.numero);
                break;
            case '*':
                mpz_mul(resultado.numero, a.numero, b.numero);
                break;
            default:
                mpz_clear(a.numero);
                mpz_clear(b.numero);
                mpz_clear(resultado.numero);
                free(resultados);
                return 1;
        }

        tamanhoNumero++;
        resultados = realloc(resultados, tamanhoNumero * sizeof(BigNumber));
        criaBigNumber(&resultados[tamanhoNumero - 1], 0);
        mpz_set(resultados[tamanhoNumero - 1].numero, resultado.numero);
    }

    for (size_t i = 0; i < tamanhoNumero; i++) {
        printBigNumber(&resultados[i]);
        mpz_clear(resultados[i].numero);
    }

    free(resultados);
    mpz_clear(a.numero);
    mpz_clear(b.numero);
    mpz_clear(resultado.numero);

    return 0;
}
