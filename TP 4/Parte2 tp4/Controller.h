#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "funciones.h"
#include "get.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_autoincrementalId(LinkedList* this);
int controller_menuEditar(Employee* empleado );
Employee* controller_getElementById(LinkedList* this , int id);
int controller_getElementByIdIndex(LinkedList* this, int id);
