#include "arrayEmployes.h"
#include "funciones.h"

#define TRUE 1
#define FALSE 0

int initEmployees(Employee* list, int len){

    int i;
    int error;

    error = -1;

    if( list != NULL && list > 0  )
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
    int error;

    error = -1;

    if( list != NULL && list > 0  )
    {

        index = findEmptyPlace(list , len);

        if(index != -1){

            upperFirtsLetter(name);
            upperFirtsLetter(lastName);

            strcpy(list[index].name , name);
            strcpy(list[index].lastName , lastName);
            list[index].salary = salary;
            list[index].sector = sector;
            list[index].id = id;
            list[index].isEmpty = FALSE;

            error = 0;

        }
    }

    return error;
}

int findEmployeeById(Employee* list, int len,int id){

    int i;
    int index;

    index = -1;

    if( list != NULL && list > 0  )
    {

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
    }

    return index;
}

int removeEmployee(Employee* list, int len, int id){

    int index;
    int error;

    error = -1;

    if( list != NULL && list > 0  )
    {

        index = findEmployeeById(list,len,id);

        if(index != -1){

            list[index].isEmpty = TRUE;
            error = 0;

        }

    }
    return error;
}

int sortEmployees(Employee* list, int len, int order)

{
    int i;
    int j;
    Employee aux;
    int error;

    error = -1;
    if( list != NULL && len > 0){

        error = 0;

        if( order == 0 ){

            for(i = 0; i < len-1; i++){

                for(j = i+1; j < len; j++)
                {
                    if( list[i].isEmpty == FALSE && list[i].sector > list[j].sector)//ordena por sector
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }

                }

            }
            for(i = 0; i < len-1; i++){
                for(j = i+1; j < len ; j++)
                {
                    if( list[i].isEmpty == FALSE &&  list[i].sector == list[j].sector)//si los sectores son iguales te ordena por apellido
                    {
                        if(strcmp(list[i].lastName,list[j].lastName) > 0){

                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;

                        }
                    }
                }
            }
        }
        else
        {
            for(i = 0; i < len-1; i++){

                for(j = i+1; j < len; j++)
                {
                    if(list[i].isEmpty == FALSE &&  list[i].sector < list[j].sector)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }

                }

            }
            for(i = 0; i < len-1; i++){
                for(j = i+1; j < len ; j++)
                {
                    if(list[i].isEmpty == FALSE &&  list[i].sector == list[j].sector)
                    {
                        if(strcmp(list[i].lastName,list[j].lastName) < 0){

                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;

                        }
                    }
                }
            }
        }
    }

    return error;

}

int printEmployees(Employee * list, int length){

    int i;

    if( list != NULL && list > 0  )
    {

        printf("----------------------EMPLEADOS----------------------\n\n");


        for(i = 0; i < length ; i++){

            if(list[i].isEmpty != TRUE){

                printf("\n%5d%15s%15s%15.2f%5d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary, list[i].sector);

            }

        }
    }
    return 0;
}

int findEmptyPlace(Employee* list , int length){

    int i;
    int index;

    index = -1;

    if( list != NULL && list > 0  )
    {
        for(i = 0; i < length ; i++)
        {

            if(list[i].isEmpty == TRUE)
            {

                index = i;
                break;

            }
        }
    }
    return index;

}


int modifyEmployee(Employee* list , int length, int index){

    char auxName[51];
    char auxLastName[51];
    int auxSector;
    float auxSalary;
    int conf;
    int  op;
    int error;

    error = -1;

    if( list != NULL && list > 0  )
    {
        error = 0;

        if(index != -1){

            do{

                op = menu("\nQue desea modificar?\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector.\n5-Cancelar\n");

                switch(op){

                    case 1:

                        GetString("\nIngrese el nuevo nombre del empleado: ","\nPor favor el nombre solamente debe contener letras: " ,auxName);

                        printf("\nEsta seguro que desea modificar el nombre de %s a %s? ", list[index].name , auxName);

                        conf = getConfirm(" (Y/N). ");

                        if( conf == 1){

                            strcpy(list[index].name, auxName);
                            printf("\nModificacion exitosa");

                            }else{

                                printf("\nOperacion cancelada.");

                            }

                        break;
                    case 2:

                        GetString("\nIngrese el apellido del empleado: ","\nPor favor el apellido solamente debe contener letras: ",auxLastName);

                        printf("\nEsta seguro que desea modificar el apellido de %s a %s? ", list[index].lastName , auxLastName);

                        conf = getConfirm(" (Y/N). ");

                        if( conf == 1){

                            strcpy(list[index].lastName, auxLastName);
                            printf("\nModificacion exitosa");

                        }else{

                            printf("\nOperacion cancelada.");

                        }
                        break;

                    case 3:

                        auxSalary = GetFloat("\nIngrese el nuevo salario de la persona: ","\nEl salario debe estar en numeros , Reingrese el salario: ");

                        printf("\nEsta seguro que desea modificar el salario del empleado de %f a %f? ", list[index].salary , auxSalary);

                        conf = getConfirm(" (Y/N) ");

                        if( conf == 1){

                            list[index].salary = auxSalary;
                            printf("\nModificacion exitosa");

                        }else{

                            printf("\nOperacion cancelada.");

                        }

                        break;

                    case 4:

                        auxSector = GetInt("\nIngrese el nuevo sector de la persona: ","\nEl sector debe estar en numeros, Reingrese el sector: ");

                        printf("\nEsta seguro que desea modificar el sector del empleado de %d a %d? ", list[index].sector , auxSector);

                        conf = getConfirm(" (Y/N) ");

                        if( conf == 1){

                            list[index].sector = auxSector;
                            printf("\nModificacion exitosa");

                        }else{

                            printf("\nOperacion cancelada.");

                        }
                        break;

                    case 5:

                        printf("operacion cancelada");

                        break;

                    default:
                        printf("opcion no valida");
                    }

            }while(op != 5);
        }
    }

    return error;
}


int countEmployee(Employee* list , int length){

    int i;
    int count;

    count = -1;

    if( list != NULL && list > 0  )
    {
        count = 0;

        for(i = 0 ; i < length ; i++){

            if( list[i].isEmpty == FALSE)
            {
                count++;
            }

        }
    }

    return count;

}

float salarySum(Employee* list , int length)
{
    int i;
    float sum;

    sum = -1;

    if( list != NULL && list > 0  )
    {
        sum = 0;

        for(i = 0; i< length; i++){

            if(list[i].isEmpty == FALSE){

                sum += list[i].salary;

            }
        }
    }

    return sum;

}

float averageSalary(Employee* list , int length){

    int cantEmployes;
    float average;
    float sum;
    //int i;

    average = -1;

    if( list != NULL && list > 0  )
    {

        average = 0;

        sum = salarySum(list , length);

        cantEmployes = countEmployee(list , length);

        average = sum/cantEmployes;
    }

    return average;
}

int aboveAverageEmployees(Employee* list , int length){

    int average;
    int i;
    int count;

    count  =-1;

    if( list != NULL && list > 0  )
    {
        count = 0;
        average = averageSalary(list , length);

        for(i = 0; i < length; i++){

            if(list[i].salary > average)
            {
                count++;
            }

        }
    }
    return count;
}
