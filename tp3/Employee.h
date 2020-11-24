#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funciones.h"
#include "get.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);

int employee_print(Employee* this);

void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int Employee_askName(char* nombre , char* text ,char* errorText);
int Employee_askHorasTrabajadas( char* text ,char* errorText);
int Employee_askSueldo( char* text ,char* errorText);

int Employee_modifyName(Employee* empleado  , char* text , char* errorText );
int Employee_modifySueldo(Employee* empleado  , char* text , char* errorText );
int Employee_modifyHorasTrabajadas(Employee* empleado  , char* text , char* errorText );

int employee_compareBySueldo(void* this ,void* this2);
int employee_compareByHorasTrabajadas(void* this ,void* this2);
int employee_compareByNombre(void* this ,void* this2);
int employee_compareById(void* this ,void* this2);



#endif // employee_H_INCLUDED
