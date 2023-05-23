//Algoritmo iterativo para Busca Binária ou Pesquisa Binária
//   BUSCA_BINARIA( V[], inic, fim, chave )
//      int sup = fim-1 // limite superior (termina em um número a
//                      // menos. 0 a 9 são 10 números)
//      int meio
//      enquanto( inic <= sup )
//         meio = (inic + sup)/2;
//         se chave == V[meio] então
//              devolva meio
//		   fimse
//         se chave < V[meio] então
//              sup = meio-1
//         senão
//              inic = meio+1
//      fim_enquanto
//      devolva -1   // não encontrado

// Desafio para  encontra o valor desejado por busca binária

#include <stdio.h>
#include <sys/timeb.h>
#include <math.h>

int busca_binaria(int V[], int inicio, int fim, int chave)
{
   int meio, sup = fim - 1; // limite superior (termina em um n�mero a
                            // menos. 0 a 9 s�o 10 n�meros)
   while( inicio <= sup )
   {
      meio = (inicio + sup) / 2;
      if( chave == V[meio] )
      {
	     return meio;
      }
      if( chave < V[meio] )
      {
         sup = meio - 1;
      }
	  else
      {
         inicio = meio + 1;
      }
   }
   return -1;
}

int main(void)
{
    int vetor[12] = {1,2,3,5,7,9,10,30,77,90,95,97}; // necessário manter o vetor ordenado 
    int res = 0;

    res = busca_binaria(vetor,0,12,97); // chamando a função()
    printf("%d\n",res); // retorno dos valores

    res = busca_binaria(vetor,0,12,77); // chamando a função()
    printf("%d\n",res); // retorno dos valores

    return 0; 
}