#include <stdio.h>
#include <stdlib.h>

struct tipo_no
{
   int num;
   struct tipo_no *prox;
};

void mostraLista(struct tipo_no *parm);
struct tipo_no *insereNo(struct tipo_no **parm);

int main(void)
{
   int num;
   struct tipo_no *head_par = NULL, *head_impar = NULL, *novo;
   do{
      printf("Digite o numero: ");
      scanf("%d", &num);
      if(num >= 0)
      {
         if(num % 2 == 0)
         {
            printf("par\n");
            novo = insereNo(&head_par);
            novo->num = num;
		 }
		 else
       {
            printf("impar\n");
            novo = insereNo(&head_impar);
            novo->num = num;
		 }
	  }
   }while(num >= 0);

   printf("Pares:\n");
   mostraLista(head_par);
   printf("\nImpares:\n");
   mostraLista(head_impar);

   return 0;  
}
struct tipo_no *insereNo(struct tipo_no **parm)
{
   struct tipo_no *nova;
   if(!(nova = malloc(sizeof(struct tipo_no))))
   {
      printf("Falta de memoria! \n");
      exit(1);
   }
   nova->prox = *parm; //Insere novo no na lista ligada
   *parm = nova;  
   return nova;
}
void mostraLista(struct tipo_no *parm)
{
   while( parm != NULL)
   {
      printf("Valor: %d \n", parm->num);
      parm = parm->prox;
   }
}

