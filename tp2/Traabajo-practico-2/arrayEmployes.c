#include "arrayEmployes.h"
#define TRUE 1
#define FALSE 0

int initEmployees(Employee* list, int len){

    int i;
    int error;

    error = -1;

    if(!( list < 0 || list == NULL))
    {
        for(i = 0; i < len ;  i++){
            list[i].isEmpty = TRUE;
        }
        error = 0;
    }

    return error;

}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){

    int index;

    index = findEmptyPlace(list , len);

    strcpy(list[index].name , name);
    strcpy(list[index].lastName , lastName);
    list[index].salary = salary;
    list[index].sector = sector;
    list[index].id = id;
    list[index].isEmpty = FALSE;



    return 0;
}

int findEmployeeById(Employee* list, int len,int id){

    int i;
    int index;

    index = -1;

    if( id > 0 )
    {
        for(i = 0; i < len ; i++)
        {
            if( list[i].id == id && list[i].isEmpty == FALSE)
            {
                index = i;
            }
        }
    }
    return index;
}

int removeEmployee(Employee* list, int len, int id){

    int index;
    int error;

    error = -1;

    index = findEmployeeById(list,len,id);

    if(index != -1){

        list[index].isEmpty = TRUE;
        error = 0;

    }

    return error;
}

int sortEmployees(Employee* list, int len, int order){

    int i;
    int j;
    int error;
    Employee aux;

    error = -1;

    if( !(list < 0 || list == NULL)){

    error = 0;

        for(i = 0 ; i < (len - 1 ); i++){

            for(j = (i+1) ; j < len ; j++ ){

                if( order == 1){

                    if(strcmp(list[i].lastName ,list[j].lastName) )
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j]= aux;
                    }
                }
                else{

                    if(list[i].lastName < list[j].lastName)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j]= aux;
                    }
                }
            }
        }
    }

    return error;

}

int printEmployees(Employee * list, int length){

    int i;

    printf("ID-----------NAME-----------LAST NAME-----------SALARY-----------SECTOR\n\n");

    for(i = 0; i < length ; i++){
        if(list[i].isEmpty != TRUE){
            printf("\n%d----------%s----------%s----------%.2f----------%d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary, list[i].sector);
        }

    }

    return 0;
}

int findEmptyPlace(Employee* list , int length){

    int i;
    int index;

    index = -1;

    for(i = 0; i < length ; i++)
    {
        if(list[i].isEmpty == TRUE)
        {
            index = i;
            break;
        }
    }

    return index;

}

