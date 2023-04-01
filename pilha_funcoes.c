#include <stdio.h>
#include <stdlib.h>

struct tipo_no
{
   int num;
   struct tipo_no *prox;
};

int isEmpty(struct tipo_no *parm);           //0= vazia e 1= nao vazia
int top(struct tipo_no *parm);               //Devolve o valor que esta no topo da pilha
void push(struct tipo_no **parm, int valor); //Empilha valor na pilha
int pop(struct tipo_no **parm);              //Desempilha o elemento do topo da pilha

int main(void)
{
   struct tipo_no *topo = NULL;
   int pos;

   for( pos = 1; pos < 6; pos++ )
   {
      push(&topo, pos);
      printf("Valor do topo= %d \n", top(topo));
   }
   printf("\nRemovendo os valores da pilha...\n\n");
   while(topo != NULL)
   {
      printf("Valor retirado: %d \n", pop(&topo));
   }
   
   return 0;  	
}
int isEmpty(struct tipo_no *parm) //0= vazia e 1= nao vazia
{ 
   if( parm == NULL)
   {
      return 0;
   }
   else
   {
      return 1;
   }
}

int top(struct tipo_no *parm) //Devolve o valor que esta no topo da pilha
{ 
   return parm->num;
}

void push(struct tipo_no **parm, int valor) //Empilha valor na pilha
{ 
   struct tipo_no *novo;
   if(!(novo = malloc(sizeof(struct tipo_no))))
   {
      printf("Falta de memoria! \n");
      exit(1);
   }
   novo->num = valor;
   novo->prox = *parm; //Insere novo no na lista ligada
   *parm = novo;
}
int pop(struct tipo_no **parm)
{
   int valor;
   struct tipo_no *remover;

   if(*parm == NULL) // Pilha vazia
   {  
      printf("Lista vazia! \n");
      exit(2);
   }
   remover = *parm;
   valor = remover->num;
   *parm = (*parm)->prox;
   free(remover); // liberar a pilha
   return valor;
}


