#include "regras.h"

int calcularMaxMovimentos(int *qtdDiscos)
{
    int i, total = 1;
    for (i = 1; i < *qtdDiscos; i++)
    {
        total = total * 2 + 1;
    }
    return total;
}

void estabelecerRegras(tipoRegra *R, int *max_j)
{
    int booler;
    do
    {
        booler = 0;
        printf("\tREGRAS GERAIS\n\n");
        printf("Quantos monges irão jogar: ");
        scanf("%d", &R->qtd_jogadores);
        printf("Quantidade de discos: ");
        scanf("%d", &R->qtd_discos);
        if (R->qtd_discos < 3 || R->qtd_discos > 24)
        {
            printf("\nQuantidade não permitida!");
            __fpurge(stdin);
            getchar();
            booler = 1;
        }
        else
        {
            if (*max_j == 1)
            {
                R->max_vitorias = 1;
            }
            else
            {
                printf("Quantos jogadores poderão terminar: ");
                scanf("%d", &R->max_vitorias);
                if (R->max_vitorias < 1 || R->max_vitorias > *max_j)
                {
                    printf("\nQuantidade não permitida!");
                    __fpurge(stdin);
                    getchar();
                    booler = 1;
                }
            }
        }
        if (!booler)
        {
            printf("\nOBS.: Para desistir da partida, digite 0 a qualquer momento!");
            __fpurge(stdin);
            getchar();
        }
        system("clear");
    } while (booler);
    R->max_movimentos = calcularMaxMovimentos(&R->qtd_discos);
    R->contador_vics = 0;
}