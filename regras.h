#include "jogo.h"

typedef struct
{
    int qtd_jogadores, max_movimentos, max_vitorias, contador_vics, qtd_discos;
} tipoRegra;

int calcularMaxMovimentos(int *qtdDiscos);

void estabelecerRegras(tipoRegra *R, int *max_j);