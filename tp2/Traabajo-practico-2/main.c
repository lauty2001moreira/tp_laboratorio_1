#include "arrayEmployes.h"
#include "funciones.h"
#define FALSE 0

#define T 5

int main()
{
    int op;
    int opCase4;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    int auxId;
    int conf;

    int order;
    int flagEmpleadoIngresado;
    int index;

    Employee sEmployees[T]; //={ {1 , "Lautaro" , "moreira" , 15000 , 1 , FALSE},
                 /*{2, "German","Gutierrez", 21000, 2 , FALSE},
                 {3, "Franco","Rolando",32000,2, FALSE},
                 {4, "Nicolas" , "Birriel" ,42000 , 2 ,FALSE},
                 {5, "Octavio" , "Costa" , 20420, 1 , FALSE}};*/


    flagEmpleadoIngresado = 0 ;

    if(initEmployees(sEmployees, T) == 0){

        do{

            op =  menu("\n1-ALTA.\n2-MODIFICAR.\n3-BAJA.\n4-INFORMAR.\n5-SALIR.");

            switch(op){

                case 1:

                    printf("\n\n------------ALTA------------\n\n");

                    index = findEmptyPlace(sEmployees, T);

                    if(index != -1){

                        GetString("\nIngrese el nombre del empleado: ","\nPor favor el nombre solamente debe contener letras: " ,auxName);
                        GetString("\nIngrese el apellido del empleado: ","\nPor favor el apellido solamente debe contener letras: ",auxLastName);

                        auxSalary = GetFloat("\nIngrese el salario del empleado: ", "\nError el salario solamente debe contener numeros: ");
                        auxSector = GetInt("\nIngrese el numero del sector del empleado: ", "\nError el sector solamente debe contener numeros: ");

                        auxId = index + 1;

                        if(addEmployee(sEmployees , T , auxId, auxName, auxLastName, auxSalary , auxSector) != -1)
                        {

                            flagEmpleadoIngresado = 1;
                            printf("\nEmpleado ingresado con exito.\n");

                        }else{

                            printf("\nHubo un error al ingresar el empleado.\n");

                        }

                    }else{

                        printf("\nNo hay mas lugar disponible.");

                    }


                    break;

                case 2:

                    printf("\n\n------------MODIFICAR------------\n\n");

                    if(flagEmpleadoIngresado != 0){

                        do{

                            printEmployees(sEmployees, T);

                            auxId = GetInt("\nIngrese el id del empleado a modificar: ","\nEl ID tiene que ser numerico, Reingrese el id: ");

                            index = findEmployeeById(sEmployees, T, auxId);

                            if(index != -1 ){

                                modifyEmployee(sEmployees , T , index);

                            }else{

                                printf("\nError id no encontrado");
                            }

                            conf = getConfirm("\nDesea modificar otro empleado? (Y/N):");

                        }while(conf == 1);


                    }else{

                        printf("\nPrimero cargue almenos un empleado para realizar esta accion.");

                    }

                    break;

                case 3:

                    if(flagEmpleadoIngresado != 0){

                        do{

                            printf("\n\n-----------BAJA------------\n\n");

                            printEmployees(sEmployees, T);

                            auxId = GetInt("\nIgrese el ID del empleado a eliminar: ", "\nEl ID debe contener solamente numeros: ");
                            index = findEmployeeById(sEmployees , T , auxId );

                            if(index != -1){

                                conf = getConfirm("\nEsta seguro que desea eliminar al empleado? (Y/N) ");
                                if(conf == 1){

                                    sEmployees[index].isEmpty = 1;
                                    printf("\nEmpleado eliminado. ");
                                }
                                else{
                                    printf("\nOperacion cancela.\n");
                                }

                            }else{

                                printf("\nEmpleado no encontrado en la nomina.");

                            }

                            conf = getConfirm("\nDesea buscar otro empleado? (Y/N):");

                        }while(conf == 1);

                    }else{

                        printf("\nPrimero cargue al menos un empleado para realizar esta accion.");

                    }

                    break;

                case 4:

                    if(flagEmpleadoIngresado == 1){

                        printf("\n\n------------INFORMAR------------\n\n");

                        opCase4 = menu("\n1-Listar los empleados alfabeticamente por apellido y sector.\n2-Mostrar total y el promedio de los empleados y cuantos empleados superan el promedio.\n");

                        switch(opCase4){

                            case 1:

                                order = menu("\n0-Ordenar empleados de mayor a menor \n1-Ordenar empleados de menor a mayor.");

                                sortEmployees(sEmployees , T , order);

                                printEmployees(sEmployees , T);

                                break;

                            case 2:
                                //ACA HACER LO DEL PROMEDIO DE SALARIOS
                                break;

                            default:
                                printf("\nError opcion no valida.\n");


                        }
                    }else{

                         printf("\nPrimero cargue al menos un empleado para realizar esta accion.");

                    }

                    break;


                case 5:

                    break;

                default:
                    printf("Error ingrese una  opcion valida");
            }


        }while( op != 5);

    }
    else
    {

        printf("\nERROR AL GENERAR LOS EMPLEADOS");

    }

    return 0;

}

