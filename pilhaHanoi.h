#include "disco.h"

typedef struct
{
   int topo;
   int capacidade;
   int numero;
   char d_base[100], d_topo[100];
   tipoDisco *disco;
} tipoPilha;

void criarPilha(tipoPilha *pilha, int *capacidade, int num);

void inicializarPilha(tipoPilha *pilha);

int estavazia(tipoPilha *pilha);

int estacheia(tipoPilha *pilha);

void empilhar(tipoPilha *pilha, tipoDisco *disco);

tipoDisco *desempilhar(tipoPilha *pilha);