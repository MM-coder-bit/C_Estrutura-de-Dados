#include <stdio.h>

int calculaProd (int *ParmValor1, int ParmValor2);

int main(void)
{
    int pri = 5, seg =2;
    printf("Resultado: %d \n", calculaProd(&pri,seg));
    printf("Pri: %d \n",pri);
    printf("Seg: %d\n",seg);
}

int calculaProd(int *ParmValor1, int ParmValor2)
{
    *ParmValor1 = *ParmValor1 * ParmValor2;
    return *ParmValor1;
}