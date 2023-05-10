int calculaDobro(int parmValor)
{
    if (parmValor <= 1)
    {
        return 1;
    }
    return parmValor * calculaDobro(parmValor-1);
}  

// Indique a alternativa correta:
// a.
// 
// esta é uma função recursiva porque retorna dobros
// b.
// 
// esta é uma função recursiva porque ela chama a si mesma diretamente
// c.
// 
// esta é uma função recursiva porque retorna um produto de dois números inteiros
// d.
// 
// esta não é uma função recursiva porque retorna o tipo inteiro
// e.
// 
// esta é uma função recursiva porque possui um parâmetro do tipo inteiro