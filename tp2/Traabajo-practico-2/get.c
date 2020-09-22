#include <stdio_ext.h>
#include <stdlib.h>
#include "validaciones.h"

void GetString(char *text, char *errorText, char *auxString){

    printf("%s",text);
    __fpurge(stdin);
    scanf("%s",auxString);

    while(ValidarString(auxString) == 1){

        printf("%s",errorText);
        scanf("%s",auxString);
    }
}


float GetFloat(char *text, char *errorText)
{


    char num[10];
    float numero;

    printf("%s",text);
    scanf("%s",num);

    while(ValidarNumeroConComa(num) == 1){

        printf("%s",errorText);
        scanf("%s",num);

    }

    numero = atof(num);

    return numero;
}

int GetInt(char *text, char *errorText)
{

    char num[10];
    int numero;

    printf("%s",text);
    scanf("%s",num);

    while(ValidarNumero(num) == 1){

        printf("%s",errorText);
        scanf("%s",num);

    }

    numero = atoi(num);

    return numero;
}

int getConfirm(char* text){

    char conf;
    int ret;

    ret = 0;

    printf("%s",text);
    __fpurge(stdin);
    scanf("%c",&conf);

    if(conf == 'Y' || conf == 'y'){
        ret = 1;
    }

    return ret;
}
