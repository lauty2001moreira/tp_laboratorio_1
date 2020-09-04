#include <stdio.h>
#include <stdlib.h>



float get_float(char texto[])
{
    float numero;
    printf(texto);
    scanf("%f",&numero);
    return numero;
}
int get_int(char texto[])
{
    int numero;
    printf(texto);
    scanf("%d",&numero);
    return numero;
}

