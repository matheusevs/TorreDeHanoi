#include "pilhaHanoi.h"

typedef struct
{
    int mov, mov_totais, pontuacao, finalzado;
    tipoPilha *pilha;
} tipoJogo;

tipoJogo *prepararJogo(int *qtd_discos);

void telaJogo(tipoJogo *jogo);

int pontuar(tipoPilha *P);

int despontuar(tipoPilha *pilha);

int jogar(tipoJogo *jogo);