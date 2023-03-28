//  Rev.3
//  Inserir 5 vari�veis din�micas com a estrutura 
//  tipo_no e depois mostre os valores digitados pelo usuario

#include <stdio.h>
#include <stdlib.h>

struct tipo_no
{
   int num;
   struct tipo_no *prox; // apontador para o proximo nó
};

struct tipo_no *insere_no(struct tipo_no **parm);

void mostrar_lista(struct tipo_no *parm); // Declarando como void!!!

int main(void)
{
   int pos=0, varLocal=0;	
   struct tipo_no *head, *nova;
   head = NULL;

   while(varLocal >= 0)
   { 
     printf("Digite o %d valor: ",pos+1);
	 scanf("%d", &varLocal); 
     if (varLocal >= 0)
        {
           nova = insere_no(&head);
           (nova->num) = varLocal;
            mostrar_lista(head);
        }
   }
   //Passeio pela lista ligada
   mostrar_lista(head);
   return 0;
}

struct tipo_no *insere_no(struct tipo_no **parm) // **parm = recebe a referencia da memória
{
    struct tipo_no *aux;

    if(!(aux = malloc(sizeof(struct tipo_no))))
    {
        printf("Falta de memoria\n");
        exit(-1);
    }

    aux->prox = *parm; // insere novo nó na lista ligada
    *parm = aux;
    return aux;    
}

void mostrar_lista(struct tipo_no *parm)
{
   while(parm != NULL)
   {
      printf("Valor: %d \n", parm->num); // pega o conteudo 
      parm = parm->prox; // receba o endereço da posição do proximo bloco
   }
}   	
