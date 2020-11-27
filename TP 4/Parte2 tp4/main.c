#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
    int op;
    int empleadosCargados;
    int error;

    LinkedList* employeeList;

    employeeList = ll_newLinkedList();

    do
    {
        op = menu("Menu:\n\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n10. Salir\n");

        switch(op)
        {

        case 1  :

            error = controller_loadFromText("data.csv", employeeList);

            if(error == 0)
            {
                printf("\nEmpleados cargados correcatamente.");
                empleadosCargados = 1;
            }
            else if(error == 1)
            {
                printf("\nLos empleados ya fueron cargados.");

            }
            else
            {
                printf("\nError al cargar los empleados");
            }
            pressAKeyAndClear();
            break;

        case 2:


            error = controller_loadFromBinary("data.bin", employeeList);

            if(error == 0)
            {

                printf("\n\nEmpleados cargados correcatamente.");
                empleadosCargados = 1;

            }
            else if (error == 1)
            {

                printf("\nLos empleados ya fueron cargados.");
            }
            else
            {

                printf("\nError al cargar los empleados");
            }

            pressAKeyAndClear();
            break;

        case 3:

            if(empleadosCargados == 1)
            {
                if(controller_addEmployee(employeeList) == 1){
                    printf("\nEmpleado ingresado correctamente.");
                }else{
                    printf("\nHubo un error al cargar el empleado.");
                }
            }
            else
            {
                printf("\nAntes de realizar alguna modificacion ingrese a la opcion cargar empleados.");
            }
            pressAKeyAndClear();

            break;

        case 4:

            if(empleadosCargados == 1)
            {
                if(controller_editEmployee(employeeList) == 1 ){

                    printf("\nEmpleado modificado exitosamente.");
                }else{

                    printf("\nHubo un error al modificar el empleado.");
                }
            }
            else
            {
                printf("\nAntes de realizar alguna modificacion ingrese a la opcion cargar empleados.");
            }
            pressAKeyAndClear();

            break;

        case 5:
            if(empleadosCargados == 1)
            {

                error = controller_removeEmployee(employeeList);

                if(error == 1){

                    printf("\nEmpleado eliminado correctamente");

                }else if(error == -2){

                    printf("\nEl id ingresado no existe.");

                }else{

                    printf("\nHubo un error al eliminar el empleado");
                }

            }
            else
            {
                printf("\nAntes de realizar alguna modificacion ingrese a la opcion cargar empleados.");
            }
            pressAKeyAndClear();
            break;

        case 6:
            if(empleadosCargados == 1)
            {

                error = controller_ListEmployee(employeeList);

                if(error == -1)
                {
                    printf("\nHubo un error al mostrar los empleados");
                }

            }
            else
            {
                printf("\nAntes de realizar alguna modificacion ingrese a la opcion cargar empleados.");
            }
            pressAKeyAndClear();

            break;

        case 7:
            if(empleadosCargados == 1)
            {
                controller_sortEmployee(employeeList);
            }
            else
            {
                printf("\nAntes de realizar alguna modificacion ingrese a la opcion cargar empleados.");
            }
            pressAKeyAndClear();

            break;

        case 8:
            if(controller_saveAsText("data.csv", employeeList) == 1)
            {
                printf("\nEmpleados guardados correctamente");
            }
            else
            {
                printf("\nHubo un error al guardar empleados.");
            }
            pressAKeyAndClear();

            break;
        case 9:
            if( controller_saveAsBinary("data.bin", employeeList) == 1)
            {
                printf("\nEmpleados guardados correctamente.");

            }
            else
            {
                printf("\nHubo un error al guardar empleados.");
            }
            pressAKeyAndClear();

            break;
        case 10:
            printf("SALIR");
            break;
        default:
            printf("Error opcion incorrecta. reingrese una opcion.");
            pressAKeyAndClear();
        }

    }
    while(op != 10);

    return 0;
}
