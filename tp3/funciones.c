#include "funciones.h"
int SortArray(int* array, int len)
{

    int i;
    int j;
    int aux;
    int error;

    error = -1;

    if(!(array == NULL && array < 0))
    {

        error = 0;

        for( i = 0; i< (len - 1); i++)
        {

            for( j = ( i + 1 ) ; j < len ; j++)
            {
                if(array[i] < array[j])
                {

                    aux  =  array[i];
                    array[i] =  array[j];
                    array[j] =  aux ;

                }
            }
        }
    }

    return error;
}


int SorArrayOfStrings(char *array[], int len)
{

    int i;
    int j;
    char *aux;
    int error;

    error = -1;

    if(!(array == NULL && array < 0))
    {

        error = 0;

        for( i = 0; i< (len - 1); i++)
        {

            for( j = ( i + 1 ) ; j < len ; j++)
            {
                if(strcmp(array[i],array[j]) < 0)
                {

                    aux  =  array[i];
                    array[i] =  array[j];
                    array[j] =  aux ;

                }
            }
        }
    }

    return error;

}

int menu(char *text)
{

    int op;

    printf("%s",text);
    op = GetInt("\nIngrese una opcion: ","\nError opcion no valida, reingrese una opcion: ");

    return op;
}

int upperFirtsLetter(char* word)
{

    int i ;
    int len;

    len = strlen(word);

    for(i = 0; i < len ; i++)
    {
        word[i]= tolower(word[i]);
    }

    word[0] = toupper(word[0]);

    return 0;

}


void pressAKeyAndClear(void)
{

    printf("\n\nPresione una tecla para continuar: ");
    __fpurge(stdin);
    getc(stdin);
    system("clear");

}

int SortFloatArray(float* array,int len )
{

    int i;
    int j;
    float aux;
    int error;

    error = -1;

    if(!(array == NULL && array < 0))
    {

        error = 0;

        for( i = 0; i< (len - 1); i++)
        {

            for( j = ( i + 1 ) ; j < len ; j++)
            {
                aux  =  array[i];
                array[i] =  array[j];
                array[j] =  aux ;
            }
        }
    }

    return error;


}

