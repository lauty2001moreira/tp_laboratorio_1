#include "funciones.h"

int menu(char *text){

    int op;

    printf("%s",text);
    op = GetInt("\nIngrese una opcion: ","\nError opcion no valida, reingrese una opcion: ");

    return op;
}

int upperFirtsLetter(char* word){

    int i ;
    int len;

    len = strlen(word);

    for(i = 0; i < len ; i++){
        word[i]= tolower(word[i]);
    }

    word[0] = toupper(word[0]);

    return 0;

}
