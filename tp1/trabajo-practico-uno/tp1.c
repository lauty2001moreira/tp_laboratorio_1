#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "calculadora.h"
#include "validaciones.h"
#include "get.h"
#include "menu.h"

#define WAIT_TIME 2

void Calculadora(){

    int op;
    float suma;
    float resta;
    double multiplicacion;
    float division;
    long long int factorial_A;
    long long int factorial_B;
    float numero_Uno;
    float numero_Dos;
    int flag_Numero_Uno_Ingresado;
    int flag_Numero_Dos_Ingresado;
    int flag_Operaciones_Calculadas;
    int flag_validar_numero_entero_B;
    int flag_validar_numero_entero_A;


    flag_Numero_Uno_Ingresado = 0;
    flag_Numero_Dos_Ingresado = 0;
    flag_Operaciones_Calculadas = 0;

    do{

        op = Mostrar_Menu(numero_Uno,numero_Dos,flag_Numero_Uno_Ingresado,flag_Numero_Dos_Ingresado);

        switch(op)
        {
            case 1:

                printf("----------------------PRIMER NUMERO----------------------\n");
                numero_Uno = Get_Float("Ingresar 1er operando:");
                flag_Numero_Uno_Ingresado = 1;

                system("clear");
                break;

            case 2:

                printf("----------------------SEGUNDO NUMERO----------------------\n");
                numero_Dos = Get_Float("Ingresar 2do operando: ");
                flag_Numero_Dos_Ingresado = 1;

                system("clear");
                break;

            case 3:

                if(flag_Numero_Uno_Ingresado == 1 && flag_Numero_Dos_Ingresado == 1 )
                {

                    printf("----------------------CALCULANDO OPERACIONES----------------------\n");

                    suma = Sumar( numero_Uno , numero_Dos );
                    resta = Restar( numero_Uno , numero_Dos );
                    division = Dividir( numero_Uno , numero_Dos );
                    multiplicacion = Multiplicar( numero_Uno , numero_Dos );

                    flag_validar_numero_entero_A = validar_Numero_Entero(numero_Uno);
                    if(flag_validar_numero_entero_A ==1)
                    {
                        factorial_A = Factorizar( numero_Uno);
                    }

                    factorial_B = Factorizar(numero_Dos);
                    if(factorial_B !=-1 ){
                        flag_validar_numero_entero_B = validar_Numero_Entero(numero_Dos);
                    }

                    flag_Operaciones_Calculadas = 1;

                }
                else if(flag_Numero_Uno_Ingresado == 0 && flag_Numero_Dos_Ingresado == 1 )
                {
                    printf("Falta ingresar el primer numero por favor seleccione la opcion uno y ingrese el numero.\n");

                }
                else if(flag_Numero_Uno_Ingresado == 1 && flag_Numero_Dos_Ingresado == 0 )
                {
                    printf("Falta ingresar el segundo numero por favor seleccione la opcion dos y ingrese el numero.\n");

                }
                else
                {
                    printf("Por favor ingrese los numeros antes de continuar.\n");
                }
                    sleep(WAIT_TIME);
                    system("clear");

                break;

            case 4:

                Mostrar_Operaciones(numero_Uno , numero_Dos, suma , resta , division , multiplicacion, factorial_A , factorial_B , flag_Operaciones_Calculadas,flag_validar_numero_entero_A,flag_validar_numero_entero_B);
                flag_Operaciones_Calculadas = 0;
                break;

            case 5:

                system("clear");
                printf("Hasta luego...");
                break;

            default:

                printf("Por favor ingrese una opcion valida.\n");
                sleep(WAIT_TIME);
                system("clear");
            }

    }while(op != 5);
}

