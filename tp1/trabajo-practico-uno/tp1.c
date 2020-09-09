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
    long long int factorialA;
    long long int factorialB;
    float numeroUno;
    float numeroDos;
    int flagNumeroUnoIngresado;
    int flagNumeroDosIngresado;
    int flagOperacionesCalculadas;
    int flagValidarNumeroEnteroB;
    int flagValidarNumeroEnteroA;


    flagNumeroUnoIngresado = 0;
    flagNumeroDosIngresado = 0;
    flagOperacionesCalculadas = 0;

    do{

        op = MostrarMenu(numeroUno,numeroDos,flagNumeroUnoIngresado,flagNumeroDosIngresado);

        switch(op)
        {
            case 1:

                printf("----------------------PRIMER NUMERO----------------------\n");
                numeroUno = GetFloat("Ingresar 1er operando:");
                flagNumeroUnoIngresado = 1;

                system("clear");
                break;

            case 2:

                printf("----------------------SEGUNDO NUMERO----------------------\n");
                numeroDos = GetFloat("Ingresar 2do operando: ");
                flagNumeroDosIngresado = 1;

                system("clear");
                break;

            case 3:

                if(flagNumeroUnoIngresado == 1 && flagNumeroDosIngresado == 1 )
                {

                    printf("----------------------CALCULANDO OPERACIONES----------------------\n");

                    suma = Sumar( numeroUno , numeroDos );
                    resta = Restar( numeroUno , numeroDos );
                    division = Dividir( numeroUno , numeroDos );
                    multiplicacion = Multiplicar( numeroUno , numeroDos );

                    flagValidarNumeroEnteroA = ValidarNumeroEntero(numeroUno);
                    if(flagValidarNumeroEnteroA ==1)
                    {
                        factorialA = Factorizar( numeroUno);
                    }

                    factorialB = Factorizar(numeroDos);
                    if(factorialB !=-1 ){
                        flagValidarNumeroEnteroB = ValidarNumeroEntero(numeroDos);
                    }

                    flagOperacionesCalculadas = 1;

                }
                else if(flagNumeroUnoIngresado == 0 && flagNumeroDosIngresado == 1 )
                {
                    printf("Falta ingresar el primer numero por favor seleccione la opcion uno y ingrese el numero.\n");

                }
                else if(flagNumeroUnoIngresado == 1 && flagNumeroDosIngresado == 0 )
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

                MostrarOperaciones(numeroUno , numeroDos, suma , resta , division , multiplicacion, factorialA , factorialB , flagOperacionesCalculadas,flagValidarNumeroEnteroA,flagValidarNumeroEnteroB);
                flagOperacionesCalculadas = 0;
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

