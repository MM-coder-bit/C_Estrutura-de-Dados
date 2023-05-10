#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct teclado
{
    int tec;
    struct teclado *prox;
};

int main(void)
{
    struct teclado *prim, *nova;
    prim=NULL;
    int aux=0;
    do
    {
        printf("Digite um numero: ");
        scanf("%d",&aux);
        
        if (aux != -1)
        {
            if(!(nova = malloc(sizeof(struct teclado))))
            {
                printf("Faltou Memória! \n");
                return 1;
            }
        
            nova->tec = aux;
            nova->prox = prim;
            prim = nova;
        }
    } while (aux != -1); // nova->tec != -1

printf("\n Mostra lista \n\n");
nova = prim;
int i = 0;
    while(nova != NULL)
    {
        printf("Numero: %d \n", nova->tec);
        nova = nova->prox;
        i ++;
    }
return 0;
  
}