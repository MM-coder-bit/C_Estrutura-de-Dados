#include <stdio.h>

int calculaDobro(int parmValor);

int main(void)
{
    printf("Resultados: %d \n",calculaDobro(5));
}

int calculaDobro(int parmValor)
{
    if (parmValor <= 1)
    {
        return 1;
    }
    return parmValor * calculaDobro(parmValor-1);
}