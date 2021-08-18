#include "jogador.h"

tipoFila *criarFila()
{
    tipoFila *novo = (tipoFila *)malloc(sizeof(tipoFila));
    novo->qtd= 0;
    novo->primeiro = novo->ultimo = NULL;
    return novo;
}

void prepararJogador(tipoFila *F, int *qtd_discos)
{
    tipoJogador *novo = (tipoJogador *)malloc(sizeof(tipoJogador));
    if (F->primeiro == NULL)
    {
        F->primeiro = novo;
    }
    else
    {        
        F->ultimo->proximo = novo;
    }
    novo->proximo = F->primeiro;
    F->ultimo = novo;
    F->qtd++;
    __fpurge(stdin);
    fgets(novo->nome, 100, stdin);
    novo->jogo = prepararJogo(qtd_discos);
}

void rodada(tipoJogador *J, tipoRegra *R)
{
    int contador_vics;
    J->jogo->mov = 0;

    if (J->jogo->finalzado)
    {
        return;
    }
    while (1)
    {
        printf("MONGE: %s\n", J->nome);
        printf("Movimentos: %d/%d", J->jogo->mov, R->max_movimentos);
        printf("\t\tTOTAL: %d", J->jogo->mov_totais);
        printf("\tPontos: %d\n\n", J->jogo->pontuacao);
        telaJogo(J->jogo);

        if (J->jogo->finalzado)
        {
            printf("\nJogo Finalizado!");
            __fpurge(stdin);
            getchar();
            break;
        }
        if (J->jogo->mov == R->max_movimentos)
        {
            break;
        }
        contador_vics = jogar(J->jogo);
        if (contador_vics == -1)
        {
            if (R->max_vitorias == R->qtd_jogadores)
            {
                __fpurge(stdin);
                getchar();
                R->max_vitorias--;
            }
            contador_vics = 0;
        }
        R->contador_vics += contador_vics;
        system("clear");
    }
    system("clear");
}