#include "tabelaPontos.h"


// APS Torre de Hanói
// -Luiz Fernando Borges Vieira;
// -Matheus Eduardo Vieira de Souza;
// -João Paulo Vaz Abrão de Sá;

int main ()
{
    tipoRegra *regra_geral = (tipoRegra *)malloc(sizeof(tipoRegra));
    manipuladorTabela *pontuacoes = criarLista();
    tipoFila *jogadores = criarFila();
    tipoJogador *proximo;
    int qtd_jogadores, qtd_vics = 0, i;
    
    system("clear");
    system("clear");
    estabelecerRegras(regra_geral, &regra_geral->qtd_jogadores);
    criarFila(jogadores, &regra_geral->qtd_jogadores);
    
    printf("\tNOME DOS MONGES\n\n");
    for (i = 0; i < regra_geral->qtd_jogadores; i++)
    {
        alocarEspaco(pontuacoes);
        printf("Monge %d: ", i+1);
        prepararJogador(jogadores, &regra_geral->qtd_discos);
        pontuacoes->ultimo->jogador = jogadores->ultimo;
        printf("\n");
    }
    system("clear");
    proximo = jogadores->primeiro;
    while (regra_geral->max_vitorias != regra_geral->contador_vics)
    {
        rodada(proximo, regra_geral);
        proximo = proximo->proximo;
    }

    exibirTabelaCompleta(pontuacoes);  

    return 0;
}
