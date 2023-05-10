Em seu livro C: Como Programar. 6. ed., São Paulo: Pearson Prentice Hall, 2011. de DEITEL e DEITEL, 

os autores esclarecem que "Para uma função receber um array por uma chamada de função, a lista de parâmetros da função precisa especificar que um array será recebido.

Não é exigido que o tamanho do array esteja entre os colchetes do array."

Considere a declaração da estrutura a seguir:


#include <stdio.h>

struct tpNo
{
    float nota;
    int cod;
    struct tpNo *aptprox;
};

int main()
{

}


a.

Podemos afirmar que existe um erro de programação nesta declaração porque uma estrutura não pode usar a si mesma
b.

Uma lista ligada deve sempre ser criada usando vetores convencionais.
c.

Esta definição de estrutura serve apenas para criar listas ligadas do tipo estático
d.

 A linha "struct tpNo *aptProx;" cria uma variável para armazenar o resultado do produto de "nota" por "cod"
e.

Podemos afirmar que esta é uma declaração recursiva porque ela usa a si própria para definir um de seus compartimentos