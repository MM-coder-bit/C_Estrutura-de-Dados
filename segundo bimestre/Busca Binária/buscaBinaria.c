#include <stdio.h>
#include <stdlib.h>
struct tipoNo
{ //Cria campos do No
   int valor;
   struct tipoNo *esq, *dir;
};
struct tipoNo* criaNo( int vlr );
void mostraArvEmOrdem( struct tipoNo *pai );
void mostraArvEmPreOrdem( struct tipoNo *pai ); // VED
void mostraArvEmPosOrdem( struct tipoNo *pai );// VED

int contagem(struct tipoNo *pai);

int main(void)
{
   int pos, num, qtdNumeros;
   struct tipoNo *arv = NULL, *pai = NULL, *filho = NULL;  
   printf("Digite a quantidade de nos: ");
   scanf("%d", &qtdNumeros);
   //Carrega a arvore
   for( pos = 0; pos < qtdNumeros; pos++)
   {
      printf("Digite um numero: ");
      scanf("%d", &num);     
      pai = arv;
      filho = arv;
      while( (filho != NULL) && (num != filho->valor) )
      {
         pai = filho;
         if( num < pai->valor )
         {
            printf("Desce pela esquerda - num: %d e no: %d\n", num, pai->valor);
            filho = pai->esq;
         }
         else
         {
            printf("Desce pela direita - no: %d e num: %d\n", pai->valor, num);
            filho = pai->dir;
         }
      }
      //Aqui chegou no final da arvore ou valor esta duplicado
      if( arv == NULL )
      {
         printf("Cria a raiz\n");
         arv = criaNo( num );
         if( arv == NULL )
         {
            return 0; //FALSE
         }
      }
      else if( (filho != NULL) && (num == filho->valor) )
      {
         printf( "O valor %d esta repetido.\n", num);
      }
      else
      {
         if( num < pai->valor )
         {
            printf("Cria filho a esquerda\n");
            pai->esq = criaNo( num );
            if( pai->esq == NULL )
            {
               return 0; //FALSE
               scanf("%d", &num);
            }
         }
         else
         {
            printf("Cria filho a direita\n");
            pai->dir = criaNo( num );
            if( pai->dir == NULL )
            {
               return 0; //FALSE
               scanf("%d", &num);
            }
         }
      }
   }
   //Mostra a arvore
   printf("Exibindo a arvore:\n");

   printf("Pre Ordem:\n");
   mostraArvEmPreOrdem(arv);

   printf("Em Ordem:\n");
   mostraArvEmOrdem(arv);
  
   printf("Pos Ordem:\n");
   mostraArvEmPosOrdem(arv);

   printf("Contagem: %d\n",contagem(arv));

   return 0;
}
struct tipoNo* criaNo( int vlr 
)
{
   struct tipoNo *noAux;    //Declara um apontador para novo no
   noAux = (struct tipoNo*) malloc(sizeof(struct tipoNo)); //Aloca memoria para o novo no
   if( noAux == NULL )
   {
      printf( "Faltou memoria para alocar o no!\n");  //Nao conseguiu alocar memoria
      return NULL;
   }
   noAux->valor = vlr; //Registra o valor recebido
   noAux->esq = NULL; //Marca este No como sendo o unico da arvore
   noAux->dir = NULL;
   return noAux; //Se chegou ateh aqui eh porque foi tudo bem
};
void mostraArvEmOrdem( struct tipoNo *pai )
{
   if( pai != NULL )
   {
      mostraArvEmOrdem( pai->esq ); // E
      printf("%d\n", pai->valor);   // V
      mostraArvEmOrdem( pai->dir ); // D
   }
}

void mostraArvEmPreOrdem( struct tipoNo *pai )// VED
{
   if( pai != NULL )
   {
      printf("%d\n", pai->valor);      // V
      mostraArvEmPreOrdem( pai->esq ); // E
      mostraArvEmPreOrdem( pai->dir ); // D
   }
}

void mostraArvEmPosOrdem( struct tipoNo *pai )// EDV
{
   if( pai != NULL )
   {
      mostraArvEmPosOrdem( pai->esq ); // E
      mostraArvEmPosOrdem( pai->dir ); // D
      printf("%d\n", pai->valor);      // V
   }
}

int contagem( struct tipoNo *pai )// Contagem
{
   if( pai != NULL )
   {
     return(1 + contagem(pai->esq) + contagem(pai->dir));           
   }
     return 0;
}
