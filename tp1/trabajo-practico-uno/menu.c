#include <stdio.h>
#include <stdlib.h>
#define WAIT_TIME 2

int MostrarMenu( float NumeroUno, float NumeroDos, int FlagNumeroUnoIngresado, int FlagNumeroDosIngresado)
{
    int op;
    printf("----------------------MENU----------------------\n");

    if(FlagNumeroUnoIngresado == 0 && FlagNumeroDosIngresado == 0)
       {
           printf("1- Ingresar 1er operando (A=x).\n2- Ingresar 2do operando (B=y).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5- Salir. \n");
       }
       else if(FlagNumeroUnoIngresado == 0 && FlagNumeroDosIngresado !=0 )
       {
           printf("1- Ingresar 1er operando (A=x).\n2- Ingresar 2do operando (B=%.2f).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5- Salir. \n",NumeroDos);
       }
       else if(FlagNumeroUnoIngresado == 1 && FlagNumeroDosIngresado == 0 )
       {
           printf("1- Ingresar 1er operando (A=%.2f).\n2- Ingresar 2do operando (B=y).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5- Salir. \n",NumeroUno);
       }
       else
       {
           printf("1- Ingresar 1er operando (A=%.2f).\n2- Ingresar 2do operando (B=%.2f).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5- Salir. \n",NumeroUno,NumeroDos);
       }
    scanf("%d",&op);
    return op;
}

void MostrarOperaciones(float numeroUno,float numeroDos, float suma ,float resta , float division, double multiplicacion, long long int factorialA,long long int factorialB,int flagOperacionesCalculadas, int flag_validar_numero_entero_A, int flag_validar_numero_entero_B)
{
    system("clear");

    printf("----------------------RESULTADOS----------------------\n");

    if(flagOperacionesCalculadas == 1)
    {

        printf("a) El resultado de %.2f + %.2f es: %.2f\n",numeroUno,numeroDos,suma);

        printf("b) El resultado de %.2f - %.2f es: %.2f\n",numeroUno,numeroDos,resta);

        if(numeroDos!=0)
        {
            printf("c) El resultado de %.2f / %.2f es: %.2f\n",numeroUno,numeroDos,division);
        }
        else
        {
            printf("c) No es posible Dividir por cero\n");
        }

        printf("d) El resultado de %.2f * %.2f es: %.2f\n",numeroUno,numeroDos,multiplicacion);

        if(factorialA != -1 && factorialB != -1 && flag_validar_numero_entero_A == 1 && flag_validar_numero_entero_B == 1 )
        {
            printf("e) El factorial de %.2f es: %lld y El factorial de %.2f es: %lld\n",numeroUno,factorialA,numeroDos,factorialB);
        }
        else if(factorialA == -1 && factorialB != -1 && flag_validar_numero_entero_B == 1 )
        {
            printf("e) El factorial de %.2f no existe y El factorial de %.2f es: %lld\n",numeroUno,numeroDos,factorialB);
        }
        else if(factorialA != -1 && factorialB == -1 && flag_validar_numero_entero_A == 1 )
        {
            printf("e) El factorial de %.2f es: %lld y El factorial de %.2f no existe\n",numeroUno,factorialA,numeroDos);
        }
        else if(factorialA == -1 && factorialB == -1 )
        {
            printf("e)No existe el factorial de numeros negativos\n");
        }
        else if(factorialA != -1 && factorialB != -1 && flag_validar_numero_entero_A == 1 && flag_validar_numero_entero_B != 1)
        {
            printf("e) El factorial de %.2f es: %lld y El factorial de %.2f no existe\n",numeroUno,factorialA,numeroDos);
        }
        else if(factorialA != -1 && factorialB != -1 && flag_validar_numero_entero_A != 1 && flag_validar_numero_entero_B == 1)
        {
            printf("e) El factorial de %.2f no existe y El factorial de %.2f es %lld \n",numeroUno,numeroDos,factorialB);
        }
        else if(factorialA != -1 && factorialB != -1 && flag_validar_numero_entero_A != 1 && flag_validar_numero_entero_B != 1)
        {
            printf("e) No existe el factorial de numeros flotantes.\n");
        }
        else{
            printf("e) El factorial de %.2f no existe y El factorial de %.2f no existe\n",numeroUno,numeroDos);
        }

        sleep(4);

    }
    else
    {
        printf("Seleccione la opcion 3 y calcule las operaciones antes de mostrar los resultados.\n");

        sleep(WAIT_TIME);
        system("clear");

    }

}



