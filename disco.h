#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char desenho[50];
    int tamanho;
} tipoDisco;

void criarDisco(tipoDisco *disco, int *tamanho, int *maior);

int eMaior(tipoDisco *disco1, tipoDisco *disco2);