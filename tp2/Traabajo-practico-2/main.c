#include "arrayEmployes.h"
#define T 1000
int Agree(char *, char* );

int main()
{
    int op;
    int opCase2;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    int auxId;
    int conf;
    int empleadoAgregado;
    //char auxString[51];
    int index;


    Employee sEmployees[T];

    if(initEmployees(sEmployees, T) == 0){

        do{

            op = GetInt("Ingrese una opcion:\n1.ALTA.\n2.MODIFICAR.\n3.BAJA.\n4.INFORMAR.\n5.Salir.\n", "\nERROR Ingrese solo numeros\nIngrese una opcion:\n1.ALTA.\n2.MODIFICAR.\n3.BAJA.\n4.INFORMAR.\n5.Salir.\n");

            switch(op){

                case 1:

                    GetString("\nIngrese el nombre del empleado: ","\nPor favor el nombre solamente debe contener letras: " ,auxName);
                    GetString("\nIngrese el apellido del empleado: ","\nPor favor el apellido solamente debe contener letras: ",auxLastName);
                    auxSalary=GetFloat("\nIngrese el salario del empleado: ", "\nIngrese solamente numeros: ");
                    auxSector=GetInt("\nIngrese el numero del sector del empleado: ", "\nIngrese solamente numeros: ");
                    index = findEmptyPlace(sEmployees, T);
                    auxId = index + 1;

                    addEmployee(sEmployees , T , auxId, auxName, auxLastName, auxSalary , auxSector);

                    //printEmployees(sEmployees, T);

                    break;

                case 2:

                    printEmployees(sEmployees, T);

                    auxId = GetInt("\nIngrese el id del empleado a modificar: ","\nEl ID tiene que ser numerico, Reingrese el id: ");
                    index = findEmployeeById(sEmployees, T, auxId);

                    if(index != -1){

                        do{

                            opCase2 = GetInt("\nQue desea modificar?\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector.\n5-Cancelar\n","\nOpcion ivalida. \nQue desea modificar?\n1-Nombre.\n2-Apellido.\n3-Salario.\n4-Sector.\n5-Cancelar.\n\t");

                            switch(opCase2)
                            {

                                case 1:

                                    GetString("\nIngrese el nuevo nombre del empleado: ","\nPor favor el nombre solamente debe contener letras: " ,auxName);
                                    conf = getConfirm("\nEsta seguro que desea modificar el nombre del empleado?. (Y/N) ");

                                    if( conf == 1){

                                        strcpy(sEmployees[index].name, auxName);
                                        printf("\nModificacion exitosa");

                                    }else{
                                        printf("\nOperacion cancelada.");
                                    }

                                    break;

                                case 2:

                                    GetString("\nIngrese el apellido del empleado: ","\nPor favor el apellido solamente debe contener letras: ",auxLastName);
                                    conf = getConfirm("\nEsta seguro que desea modificar el apellido del empleado?. (Y/N) ");

                                    if( conf == 1){

                                        strcpy(sEmployees[index].name, auxName);
                                        printf("\nModificacion exitosa");

                                    }else{

                                        printf("\nOperacion cancelada.");

                                    }


                                    break;
                                case 3:

                                    auxSalary = GetFloat("\nIngrese el nuevo salario de la persona: ","\nEl salario debe estar en numeros , Reingrese el salario: ");
                                    conf = getConfirm("\nEsta seguro que desea modificar el salario del empleado?. (Y/N) ");

                                    if( conf == 1){

                                        sEmployees[index].salary = auxSalary;
                                        printf("\nModificacion exitosa");

                                    }else{

                                        printf("\nOperacion cancelada.");

                                    }

                                    break;

                                case 4:

                                    auxSector = GetInt("\nIngrese el nuevo sector de la persona: ","\nEl sector debe estar en numeros, Reingrese el sector: ");
                                    conf = getConfirm("\nEsta seguro que desea modificar el salario del empleado?. (Y/N) ");

                                    if( conf == 1){

                                        sEmployees[index].sector = auxSector;
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

                        }while(opCase2 != 5);

                        break;

                    }else{

                        printf("\nUsuario no encontrado.");
                    }
                case 3:

                    printEmployees(sEmployees, T);

                    auxId = GetInt("\nIgrese el ID del empleado a eliminar: ", "\nEl ID debe contener solamente numeros: ");

                    index = findEmployeeById(sEmployees , T , auxId );

                        if(index != -1){
                            sEmployees[index].isEmpty = 1;
                            printf("\nEmpleado eliminado. ");
                        }else{
                            printf("\nEmpleado no encontrado en la nomina. ");

                        }
                    break;
                case 4:
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

