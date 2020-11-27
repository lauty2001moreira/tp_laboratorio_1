#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funciones.h"
#include "get.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int cantidadDatosLeidos;
    int error = -1;
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    Employee* newEmployee;

    if (pFile != NULL && pArrayListEmployee != NULL)
    {
        error = 0;

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        do
        {
            cantidadDatosLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

            if (cantidadDatosLeidos == 4)
            {

                newEmployee = employee_newParametros(id,nombre,horasTrabajadas);
                employee_setSueldo( newEmployee, atoi (sueldo) );

                if (newEmployee != NULL)
                {
                    ll_add(pArrayListEmployee, newEmployee);
                    error = 1 ;
                }

            }
            else
            {
                error = 0;
                break;
            }

        }
        while (!feof(pFile));

    }

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error=-1;

    Employee* employee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        error = 0;
        do
        {

            employee = employee_new();

            if(employee != NULL)
            {

                fread(employee,sizeof(Employee),1,pFile);

                if(feof(pFile))
                {
                    break;
                }

                ll_add(pArrayListEmployee,employee);
                error=1;
            }
        }
        while(!feof(pFile));
    }
    return error;
}
