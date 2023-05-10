// Em seu livro C: Como Programar. 6. ed., São Paulo: Pearson Prentice Hall, 2011. de DEITEL e DEITEL, 
// 
// os autores esclarecem que "Em muitas linguagens de programação, existem duas maneiras de se chamar funções — a chamada por valor e a chamada por referência.
// 
// Quando os argumentos são passados por valor, uma cópia do valor do argumento é feita e passada para a função chamada.
// 
// As mudanças na cópia não afetam o valor original da variável na chamadora.
// 
// Quando um argumento é passado por referência, o chamador permite que a função chamada modifique o valor da variável original."
// 
// Analise o trecho de programa a seguir:


#include <stdio.h>

struct tpNo
{
    float nota;
    int cod;
    struct tpNo *aptprox;
};

struct tpNo *criaNO(struct tpNo **parmApt, int parmNum);

int main(void)
{

}

// Levando em consideração o código apresentado avalie as seguintes afirmações:
// 
// I) A declaração da estrutura tpNo serve de base para uma lista ligada.
// 
// II) A declaração da função "criaNo" contém erro de programação porque não é permitido criar uma função com dois asteriscos para um parâmetro.
// 
// III) A declaração da função "criaNo" contém erro de programação porque não é permitido usar "struct" como parâmetro de função.
// 
// IV) Na declaração da função "criaNo" o parâmetro "parmApt" deve ser passado por referência para que os ajustes realizados dentro da função também tenham validade dentro do programa principal.
// 
// Em relação a estas afirmações indique a alternativa correta:
// a.
// 
// Apenas as alternativas I e III são verdadeiras
// b.
// 
// Apenas as alternativas I e IV são verdadeiras
// c.
// 
// Apenas as alternativas II e III são verdadeiras
// d.
// 
// Apenas as alternativas III e IV são verdadeiras
// e.
// 
// Apenas as alternativas I e II são verdadeiras