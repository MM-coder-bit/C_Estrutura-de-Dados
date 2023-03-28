//merge_sort.c
//Autor: Oclair Prado
//Programa: -> ordena um vetor usando merge_sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#include <stdbool.h>

#define False 0   //False = zero
#define True 1    //True = qualquer valor diferente de zero

void selection_sort(int vet[], int tamanho);

void bubble_sort(int vet[], int tamanho);

void mostrar_vet( int vet[], int tamanho );

int main(void) {
   struct timeb start, end;
   int contador, vetor1[50000], vetor2[50000], vetor3[50000], vetor4[50000], vetor5[50000], dif;
	       
   for(contador = 0; contador < 50000; contador++)
   {
      vetor1[contador] = rand();
      vetor2[contador] = rand(); 
   }
   
   ftime(&start);

   mostrar_vet(vetor1, 20);
   selection_sort(vetor1, 50000 );
   bubble_sort(vetor1, 50000);

   ftime(&end);
   dif = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
   printf("\nTempo gasto [selection_sort]: %d ms.\n",dif);
   printf("\nTempo gasto [bubble_sort]: %d ms.\n", dif);
   mostrar_vet(vetor1, 20);
 
   return 0;
}

void mostrar_vet(int vet[], int tamanho )
{
   int pos;
   for( pos = 0; pos < tamanho; pos++ )
   {
      printf("%d, ", vet[pos] );
   }
   printf("...\n");
}

//int register ext_N, int_N, aux;
void bubble_sort(int vet[], int tamanho)
{   
    int aux, N;
    bool flag_troca = true;
    while(flag_troca == true)
    {
      flag_troca = false;
      for(N = 0; N < tamanho-1; N++)
      {
	    if (vet[N+1] < vet[N])
        { 
		    flag_troca = true;
            aux = vet[N+1];
		    vet[N] = vet[N+1];
            vet[N] = aux;
		 }
      }		 
    }
}

void selection_sort(int vet[], int tamanho){
//      para( ext_N variando de inic a fim-1 do vetor )
//         para( int_N variando de ext_N+1 a fim do vetor)
//	          se v[ext_N] > v[int_N] entao
//		         troca v[ext_N] com v[int_N]
//		      fim_se
//         fim_para
//      fim_para	

//   int register ext_N, int_N, aux;
//
//   for( ext_N = 0; ext_N < tamanho-1; ext_N++){
//      for( int_N = ext_N+1; int_N < tamanho; int_N++)
//      {
//         if( vet[ext_N] > vet[int_N])
//         {
//            aux = vet[ext_N];
//            vet[ext_N] = vet[int_N];
//            vet[int_N] = aux;
//		 }
//	  }
//   }
}

