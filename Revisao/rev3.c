#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct teclado
{
    int tec;
    struct teclado *prox;
};

// Função recursiva do print
int prin_t(struct teclado *nova)
{
    printf("Numero: %d \n", nova->tec);
    nova = nova->prox;
    return(prin_t(nova));
}

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
            printf("Endereco de memoria: %x \n",prim->prox);
        }
    } while (aux != -1); // nova->tec != -1

printf("\n Mostra lista \n\n");

// chama a função recursiva do print
nova = prim;
prin_t(nova);

return 0;
  
}