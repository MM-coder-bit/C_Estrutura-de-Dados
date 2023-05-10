#include <stdio.h>
#include <sys/timeb.h>
#include <math.h>
#include <stdlib.h>

void selection_sort(int vet[], int tamanho);
int busca_binaria(int V[], int inic, int fim, int chave);
int busca_sequencial(int V[], int inic, int fim, int chave);
void quick_sort( int ver[], int start, int end );
int partition( int vet[], int start, int end );
void swap( int vet[], int i, int j );

int main(void) 
{
   struct timeb start, end;
   int num = 0, res, tamanho = 250000, contador, vetor1[tamanho], vetor2[tamanho], dif;

   printf("\nCriando os vetores...\n");
   ftime(&start);
   for(contador = 0; contador < tamanho; contador++)
   {
      vetor1[contador] = rand();
   }
   ftime(&end);
   dif = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
   printf("\nTempo gasto criando um vetor: %d ms.\n", dif);
      
   printf("\nOrdenando os vetores...\n");
   ftime(&start);
   //selection_sort( vetor1, tamanho );
   quick_sort(vetor1, 0, tamanho-1 );
   ftime(&end);
   dif = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
   printf("\nTempo gasto [quick_sort]: %d ms.\n", dif);

   while (num != -1)
   {
      printf("\nDigite o Valor:");
      scanf("%d",&num);
      
   ftime(&start);
   res = busca_sequencial(vetor1, 0, tamanho, num);
   if( res == -1){
      printf("Numero nao encontrado [%d] \n", num);
   }
   else{
      printf("Numero encontrado na posicao [%d] \n", res);
   }
   ftime(&end);
   dif = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
   printf("\nTempo gasto [busca sequencial]: %d ms.\n", dif);
   
   ftime(&start);
   res = busca_binaria(vetor1, 0, tamanho, num);
   if( res == -1){
      printf("Numero nao encontrado [%d] \n", num);
   }
   else{
      printf("Numero encontrado na posicao [%d] \n", res);
   }
   ftime(&end);
   dif = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
   printf("\nTempo gasto [busca binaria]: %d ms.\n", dif);

   }

   return 0;
}

int busca_sequencial(int V[], int inic, int fim, int chave)
{
   int pos;
   for( pos = inic; pos < fim; pos++)
   {
      if( chave == V[pos] ){
	     return pos;
      }
   }
   return -1;   // chave n�o encontrada
}

int busca_binaria(int V[], int inic, int fim, int chave)
{
   int meio, sup = fim - 1; // limite superior (termina em um n�mero a
                            // menos. 0 a 9 s�o 10 n�meros)
   while( inic <= sup )
   {
      meio = (inic + sup) / 2;
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
         inic = meio + 1;
     }
   }
   return -1;   // chave n�o encontrada
}

void selection_sort(int vet[], int tamanho)
{
   int ext_N, int_N, aux;

   for( ext_N = 0; ext_N < tamanho-2; ext_N++){
      for( int_N = ext_N+1; int_N < tamanho-1; int_N++){
         if( vet[ext_N] > vet[int_N]){
            aux = vet[ext_N];
            vet[ext_N] = vet[int_N];
            vet[int_N] = aux;
		 }
	  }
   }
}

void quick_sort( int vet[], int start, int end )
{
   int pivot;

   if( start >= end )
   {
      return;
   }

   pivot = partition( vet, start, end );

   quick_sort( vet, start, pivot-1 );
   quick_sort( vet, pivot+1, end );
}

int partition( int vet[], int start, int end )
{
   int aux, i = start, j;

   for (j = start; j < end; j++) 
   {
      /* Elemento atual menor ou igual ao piv�? */
      if (vet[j] <= vet[end]) {
         swap(vet, i++, j);
      }
   }
   swap(vet, i, end);
   return i;
}

void swap( int vet[], int i, int j )
{
   int aux = vet[i];
   vet[i] = vet[j];
   vet[j] = aux;
}


