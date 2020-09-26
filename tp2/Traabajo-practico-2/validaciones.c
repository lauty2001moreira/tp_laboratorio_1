
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ValidarNumeroEntero(float numero)
{
    int aux;
    int flag;

    flag  = 0;
    aux = numero;

    if(numero - aux){

        flag = 0;

    }else{

        flag = 1;

    }

    return flag;
}

int ValidarNumeroFlotante(float numero)
{
    int aux;
    int flag;

    flag  = 0;
    aux = numero;

    if(numero - aux){

        flag = 1;

    }else{

        flag = 0;

    }

    return flag;
}


int ValidarString(char string[50]){

    int i;
    int error;
    int len;

    error = 0;
    len = strlen(string);

    for(i = 0; i < len ;i++){

        //if( !(isalpha(string[i]) )) Otra manera de validar strings
        if (!((string[i]==32)||(string[i]==39)||(string[i]>64&&string[i]<91)||(string[i]>96&&string[i]<123)))
        {
            error = 1;
            break;
        }
    }

    return error;
}

int ValidarNumero(char string[10]){

    int i;
    int error;
    int len;

    error = 0;
    len = strlen(string);

    for(i = 0; i < len ;i++){

        if (!( string[0] == '-' || isdigit(string[i])))
        {
            error = 1;
            break;
        }
    }

    return error;
}

int ValidarNumeroConComa(char string[50]){

    int i;
    int error;
    int len;

    error = 0;
    len = strlen(string);

    for(i = 0; i < len ;i++){

        if (!( string[0] == '-' || isdigit(string[i]) || string[i] == 46 ))
        {
            error = 1;
            break;
        }
    }

    return error;
}
