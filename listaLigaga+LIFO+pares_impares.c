#include <stdio.h>
#include <stdlib.h>

struct tipo_no
{
    int num;
    struct tipo_no *prox;
};

int isEmpty(struct tipo_no *parm);          // 0 = Vazia
int top(struct tipo_no *parm);              // acesso por valor
void push(struct tipo_no **parm,int valor); // acesso por referência (**parm)
int pop(struct tipo_no **parm);             // acesso por referência (**parm)

int main()
{

    int pos,pospar,posimpar;
    struct tipo_no *pilha_par = NULL;
    struct tipo_no *pilha_impar = NULL;
    for (pos = 0; pos < 10 ; pos++) // incrementa na pilha
    {
        if (pos % 2 == 0)
        {
            push(&pilha_par,pos);
        }
        else
        {
            push(&pilha_impar,pos);
        }
    }
    printf("Mostrando a pilha ... \n");

    while (isEmpty(pilha_par) != 0 || isEmpty(pilha_impar) != 0 )
    {
        pospar = pop(&pilha_par);
        posimpar = pop(&pilha_impar);
        printf("Par: %d - Impar: %d\n",pospar,posimpar);
    }
return 0;
}

int isEmpty(struct tipo_no *parm) // verifica se a fila esta vazia
{
    if(parm == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int top(struct tipo_no *parm)           // retorna o valor do topo 
{
    if(parm == NULL)
    {
        printf("Erro! Pilha Vazia! \n");
        exit(1);                        // sai do programa e apresenta o valor 1
    }
    return parm->num;
}

void push(struct tipo_no **parm,int valor)        // envia dados para a lista
{
    struct tipo_no *novo;                         // struct auxiliar
    if (!(novo = malloc(sizeof(struct tipo_no)))) // 'novo' recebe a alocação da memória da struct tipo_no
    {
        printf("Faltou memória!\n");
        exit(2);
    }
    novo->num = valor;  // adiciona o valor no num da struct 'novo', criada localmente
    novo->prox = *parm; // adiciona a posição do endereço do *parm (passado pelo argumento) na struct novo (local)
    *parm = novo;       // envia os dados do 'novo' para o principal (passado pelo argumento)}
}

int pop(struct tipo_no **parm)
{
    struct tipo_no *remover;
    int valor;

    if(*parm == NULL)
    {
        printf("Pilha Vazia!\n");
        exit(3);
    }

    remover = *parm;       // struct remover recebe a struct do parametro
    valor = remover->num;  // recebe o valor da remoção
    *parm = remover->prox; // recebe o valor do endereço do remover e envia para o *parm
    free(remover);         // livbera a memória
    return valor;
}
