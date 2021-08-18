#include "jogo.h"

tipoJogo *prepararJogo(int *qtd_discos)
{
    int i;
    tipoJogo *novo = (tipoJogo *)malloc(sizeof(tipoJogo));
    novo->pilha = (tipoPilha *)malloc(3 * sizeof(tipoPilha));

    for (i = 0; i < 3; i++)
    {
        criarPilha(&novo->pilha[i], qtd_discos, i + 1);
        if (!i)
        {
            inicializarPilha(&novo->pilha[i]);
        }
    }
    novo->mov_totais = 0;
    novo->pontuacao = 0;
    novo->finalzado = 0;
    return novo;
}

void telaJogo(tipoJogo *jogo)
{
    int i, j, capacidade = jogo->pilha[0].capacidade;
    for (i = capacidade; i >= -1; i--)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == -1)
            {
                printf("%s ", jogo->pilha[j].d_base);
            }
            else if (i == capacidade)
            {
                printf("%s ", jogo->pilha[j].d_topo);
            }
            else
            {
                if (i > jogo->pilha[j].topo)
                {
                    printf("%s ", jogo->pilha[j].d_topo);
                }
                else
                {
                    printf("%s ", jogo->pilha[j].disco[i].desenho);
                }
            }
        }
        printf("\n");
    }
}

int pontuar(tipoPilha *P)
{
    // Analizar qtd na pilha e pontuar caso a difenreça entre um disco e outro for 1 e baixo pra cima
    int i = 0, pontos = 0;
    while (i != P->capacidade)
    {
        if (!i)
        {
            if (P->disco[i].tamanho == P->capacidade && P->topo != -1)
            {
                pontos += 3;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (P->disco[i].tamanho == P->disco[i - 1].tamanho - 1)
            {
                pontos += 3;
            }
            else
            {
                break;
            }
        }
        i++;
    }
    return pontos;
}

int permissionarMovimento(tipoJogo *J, int *PI, int *PF, int sel)
{
    if (!sel)
    {
        if (*PI < 0 || *PI > 2)
        {
            return 1;
        }
        if (estavazia(&J->pilha[*PI]))
        {
            return 1;
        }
    }
    else
    {
        if (*PF < 0 || *PF > 2)
        {
            return 1;
        }
        if (*PI == *PF)
        {
            return 1;
        }
        if (eMaior(&J->pilha[*PI].disco[J->pilha[*PI].topo], &J->pilha[*PF].disco[J->pilha[*PF].topo]) && !estavazia(&J->pilha[*PF]))
        {
            return 1;
        }
    }
    return 0;
}

int jogar(tipoJogo *jogo)
{
    tipoDisco *auxiliar;
    int PI, PF, auxiliar_ponto;
    char op;

    // Selecionando a primeira pilha
    printf("\nDe: ");
    __fpurge(stdin);
    scanf("%d", &PI);
    if (PI == 0)
    {
        printf("\nDeseja mesmo desistir? (S para confirmar)\n\n");
        printf(">> ");
        __fpurge(stdin);
        scanf("%c", &op);
        if (op == 's' || op == 'S')
        {
            printf("\nQue pena...");
            __fpurge(stdin);
            getchar();
            jogo->finalzado = 1;
        }
        else
        {
            printf("\nBora continuar!");
            __fpurge(stdin);
            getchar();
        }
        return -1;
    }
    PI -= 1;

    if (permissionarMovimento(jogo, &PI, &PF, 0))
    {
        printf("\nMovimento inválido!");
        __fpurge(stdin);
        getchar();
    }

    // Selecionando a segunda pilha
    else
    {
        printf("Para: ");
        __fpurge(stdin);
        scanf("%d", &PF);
        if (PF == 0)
    {
        printf("\nDeseja mesmo desistir? (S para confirmar)\n\n");
        printf(">> ");
        __fpurge(stdin);
        scanf("%c", &op);
        if (op == 's' || op == 'S')
        {
            printf("\nQue pena...");
            __fpurge(stdin);
            getchar();
            jogo->finalzado = 1;
        }
        else
        {
            printf("\nBora continuar!");
            __fpurge(stdin);
            getchar();
        }
        return -1;
    }
        PF -= 1;

        if (permissionarMovimento(jogo, &PI, &PF, 1))
        {
            printf("\nMovimento inválido!");
            __fpurge(stdin);
            getchar();
        }
        else
        {
            auxiliar = desempilhar(&jogo->pilha[PI]);
            empilhar(&jogo->pilha[PF], auxiliar);
            if (jogo->pilha[PF].numero == 3 || jogo->pilha[PI].numero == 3)
            {
                jogo->pontuacao = pontuar(&jogo->pilha[2]);
            }
            jogo->mov++;
            jogo->mov_totais++;
        }

        if (estacheia(&jogo->pilha[2]))
        {
            jogo->finalzado = 1;
            return 1;
        }
    }
}