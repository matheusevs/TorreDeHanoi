#include "disco.h"

void criarDisco(tipoDisco *disco, int *tamanho, int *maior)
{
    int i, diferenca;
    diferenca = *maior + 1 - *tamanho;
    for (i = 0; i < ((*maior + 1) * 2) + 1; ++i)
    {
        if (i < diferenca || i >= (((*maior + 1) * 2) + 1) - diferenca)
        {
            disco->desenho[i] = ' ';
        }
        else
        {
            disco->desenho[i] = '=';
        }
    }
    disco->desenho[i] = '\0';
    disco->tamanho = *tamanho;
}

int eMaior(tipoDisco *disco1, tipoDisco *disco2)
{
    return (disco1->tamanho > disco2->tamanho);
}