#include <stdio.h>

int main()
{
    int quantidade, linha, coluna;

    printf("Digite a quantidade de asteristicos\n");
    scanf("%i", &quantidade);
    
    for (linha=0; linha < quantidade; linha++)
    {   
        printf("\n");
        for (coluna = 0; coluna < quantidade; coluna++)
        {
            printf("*");
        }
    }    
     return 0;
}