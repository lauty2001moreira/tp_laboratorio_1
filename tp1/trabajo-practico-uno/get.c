#include <stdio.h>
#include <stdlib.h>



float GetFloat(char texto[])
{
    float numero;
    printf(texto);
    scanf("%f",&numero);
    return numero;
}

int Get_Int(char texto[])
{
    int numero;
    printf(texto);
    scanf("%d",&numero);
    return numero;
}

