#include "jogador.h"

typedef struct Tabela
{
    tipoJogador *jogador;
    struct Tabela *proximo;
} tipoTabela;

typedef struct
{
    tipoTabela *primeiro, *ultimo;
} manipuladorTabela;

manipuladorTabela *criarLista();

void alocarEspaco(manipuladorTabela *lista);

void exibirTabela (tipoTabela *T);

void exibirTabelaCompleta(manipuladorTabela *lista);