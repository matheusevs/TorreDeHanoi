#include "tabelaPontos.h"

manipuladorTabela *criarLista()
{
    manipuladorTabela *novo = (manipuladorTabela *)malloc(sizeof(manipuladorTabela));
    novo->primeiro = novo->ultimo = NULL;
    return novo;
}

void alocarEspaco(manipuladorTabela *lista)
{
    tipoTabela *novo = (tipoTabela *)malloc(sizeof(tipoTabela));
    novo->proximo = NULL;

    if (lista->primeiro == NULL)
    {
        lista->primeiro = lista->ultimo = novo;
    }
    else
    {
        lista->ultimo->proximo = novo;
        lista->ultimo = novo;
    }
}

void exibirTabela (tipoTabela *T)
{
    printf("Nome: %s", T->jogador->nome);
    printf("Movimentos: %d\n", T->jogador->jogo->mov_totais);
    printf("Pontuacao: %d\n", T->jogador->jogo->pontuacao);
    printf("\n--------------------------------------\n");
}

void exibirTabelaCompleta(manipuladorTabela *lista)
{
    tipoTabela *auxiliar = lista->primeiro;
    printf("\tTABELA DOS MONGES\n\n");
    while (auxiliar != NULL)
    {
        exibirTabela(auxiliar);
        auxiliar = auxiliar->proximo;
    }
    __fpurge(stdin);
    getchar();
}