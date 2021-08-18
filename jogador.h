#include "regras.h"

typedef struct Jogador
{
    char nome[100];
    tipoJogo *jogo;
    struct Jogador *proximo;
} tipoJogador;

typedef struct
{
    int qtd;
    tipoJogador *primeiro, *ultimo;
} tipoFila;

tipoFila *criarFila();

void prepararJogador(tipoFila *F, int *qtd_discos); 

void rodada(tipoJogador *J, tipoRegra *R);