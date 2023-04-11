// Principal estrutura para a fila
// FIFO - First In First Out
// Fila é a junção da lista ligada + politica de acesso FIFO

#include <stdio.h>
#include <stdlib.h>
struct tipo_no
{
    int num;
    struct tipo_no *prox;
};

void inserir(struct tipo_no **parm_i, struct tipo_no **parm_f, int valor);
int remover (struct tipo_no **parm_i,struct tipo_no **parm_f);
int isEmpty(struct tipo_no *parm_i);
void mostrar_fila(struct tipo_no *parm_f);

int main()
{
    int pos;
    struct tipo_no *Fila1 = NULL;
    struct tipo_no *Fila2 = NULL;

    for (pos = 0; pos < 10; pos++) // incrementa na pilha
    {
        printf("Inserir o valor: %d\n",pos);
        inserir(&Fila1,&Fila2,pos);
    }
    printf("\nMostrar a Fila ... \n");
    mostrar_fila(Fila2);
    printf("\n");

    while (isEmpty(Fila1) != 0)
    {
        pos = remover(&Fila1,&Fila2);
        printf("Remover da lista: %d\n",pos);
    }
return 0;
}

int isEmpty(struct tipo_no *parm_i) // verifica se a fila esta vazia
{
    if(parm_i == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void inserir(struct tipo_no **parm_i, struct tipo_no **parm_f, int valor)
{
    struct tipo_no *novo;

    if (!(novo = malloc(sizeof(struct tipo_no))))
    {
        printf("Faltou Memória!\n");
        exit(1);
    }
    novo->num = valor;
    novo->prox = *parm_f;
    *parm_f = novo;

    if (*parm_i == NULL)
    {
        *parm_i = novo;
    }
}

int remover(struct tipo_no **parm_i,struct tipo_no **parm_f)
{
struct tipo_no *remover;
int valor;

if (isEmpty(*parm_i) == 0)
{
    printf("Fila Vazia!\n");
    exit(2);
}

    if (*parm_i == *parm_f)
    {
        remover = *parm_i;
        valor = remover->num;
        *parm_i = NULL;
        *parm_f = NULL;
        free(remover);
        return valor;
    }
    remover = *parm_f;

    while (remover->prox != *parm_i)
    {
        remover = remover->prox;
    }
    *parm_i = remover;
    remover = remover->prox;
    (*parm_i)->prox = NULL;
    valor = remover -> num;
    return valor;
}

void mostrar_fila(struct tipo_no *parm_f)
{
    while (parm_f != NULL)
    {
        printf("Valor: %d\n", parm_f->num);
        parm_f = parm_f->prox;
    }
    
}