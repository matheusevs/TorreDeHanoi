#include "pilhaHanoi.h"

void criarPilha(tipoPilha *pilha, int *capacidade, int num)
{
   int i;
   pilha->topo = -1;
   pilha->capacidade = *capacidade;
   pilha->numero = num;
   pilha->disco = (tipoDisco *)calloc(*capacidade, sizeof(tipoDisco));

   for (i = 0; i < ((pilha->capacidade + 1) * 2) + 1; ++i)
   {
      pilha->d_base[i] = '/';
      if (i == pilha->capacidade + 1)
      {
         pilha->d_topo[i] = '|';
      }
      else
      {
         pilha->d_topo[i] = ' ';
      }
   }
   pilha->d_topo[i] = '\0';
   pilha->d_base[i] = '\0';
}

void inicializarPilha(tipoPilha *pilha)
{
   int i;
   for (i = pilha->capacidade; i >= 1; i--)
   {
      pilha->topo++;
      criarDisco(&pilha->disco[pilha->topo], &i, &pilha->capacidade);
   }
}

int estavazia(tipoPilha *pilha)
{

   if (pilha->topo == -1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int estacheia(tipoPilha *pilha)
{
   if (pilha->topo == pilha->capacidade - 1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

void empilhar(tipoPilha *pilha, tipoDisco *disco)
{
   pilha->topo++;
   pilha->disco[pilha->topo] = *disco;
}

tipoDisco *desempilhar(tipoPilha *pilha)
{
   tipoDisco *auxiliar = &pilha->disco[pilha->topo];
   pilha->topo--;
   return auxiliar;
}