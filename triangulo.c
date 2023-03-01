#include <stdio.h>

int main()
{
    int quantidade, pos, pos2, iterador=0;

    printf("Digite a quantidade de asteristicos\n");
    scanf("%i", &quantidade);
    
    for (pos=0; pos <= quantidade; pos++)
    { 
        printf("\n");
        for (pos2 = 0;pos2 < iterador; pos2++)
        {
          printf("*");  
        }
       
       iterador++;
    }    
     return 0;
}