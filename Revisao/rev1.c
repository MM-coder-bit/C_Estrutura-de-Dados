#include <stdio.h>
#include <stdlib.h>

struct notaAluno
{
    int ra;
    float nota;
};

void insere(struct notaAluno parametro[], int tam);
void mostrar(struct notaAluno parametro[], int tam);

// main principal
int main(void)
{
    int tam=2;
    struct notaAluno vet[tam];
    insere(vet,tam);
    mostrar(vet,tam);
    return 0;
}

// insere os dados 
void insere(struct notaAluno parametro[], int tam) 
{
	int pos;
	for(pos = 0; pos < tam; pos++)
    {
        do
        {
            printf("Digite o RA: %d\n", pos+1);
            scanf("%d", &parametro[pos].ra);
            printf("Digite a nota: %i\n", pos+1 );
            scanf("%f", &parametro[pos].nota);
        } while ((parametro[pos].nota < 0 ) || (parametro[pos].nota > 10));
	}
}
// mostrar os dados
void mostrar(struct notaAluno parametro[], int tam)
{
    int pos;
    for (pos = 0; pos < tam; pos++)
    {
        printf("RA: %d e Nota: %.2f\n",parametro[pos].ra,parametro[pos].nota);
    }
}