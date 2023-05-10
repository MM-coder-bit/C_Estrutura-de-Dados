#include <stdio.h>

int main(void)
{
    int x = 5,y = 6,*p = &x;

    if (*p > y)
    {
        printf("x é maior que y\n");
    }
    else
    {
        printf("x é menor \n");
    }

    return 0;
    
}