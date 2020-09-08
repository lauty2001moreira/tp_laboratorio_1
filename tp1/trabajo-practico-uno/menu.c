#include <stdio.h>
#include <stdlib.h>
#define WAIT_TIME 2

int mostrar_Menu( float numero_Uno, float numero_Dos, int flag_Numero_Uno_Ingresado, int flag_Numero_Dos_Ingresado)
{
    int op;
    printf("----------------------MENU----------------------\n");
    if(flag_Numero_Uno_Ingresado == 0 && flag_Numero_Dos_Ingresado == 0)
       {
           printf("1- Ingresar 1er operando (A=x).\n2- Ingresar 2do operando (B=y).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5- Salir. \n");
       }
       else if(flag_Numero_Uno_Ingresado == 0 && flag_Numero_Dos_Ingresado !=0 )
       {
           printf("1- Ingresar 1er operando (A=x).\n2- Ingresar 2do operando (B=%.2f).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5- Salir. \n",numero_Dos);
       }
       else if(flag_Numero_Uno_Ingresado == 1 && flag_Numero_Dos_Ingresado == 0 )
       {
           printf("1- Ingresar 1er operando (A=%.2f).\n2- Ingresar 2do operando (B=y).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5- Salir. \n",numero_Uno);
       }
       else
       {
           printf("1- Ingresar 1er operando (A=%.2f).\n2- Ingresar 2do operando (B=%.2f).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5- Salir. \n",numero_Uno,numero_Dos);
       }
    scanf("%d",&op);
    return op;
}

void mostrar_operaciones(float numero_Uno,float numero_Dos, float suma ,float resta , float division, double multiplicacion, long long int factorial_A,long long int factorial_B,int flag_Operaciones_Calculadas, int flag_validar_numero_entero_A, int flag_validar_numero_entero_B)
{
    system("clear");

    printf("----------------------RESULTADOS----------------------\n");

    if(flag_Operaciones_Calculadas == 1)
    {

        printf("a) El resultado de %.2f + %.2f es: %.2f\n",numero_Uno,numero_Dos,suma);

        printf("b) El resultado de %.2f - %.2f es: %.2f\n",numero_Uno,numero_Dos,resta);

        if(numero_Dos!=0)
        {
            printf("c) El resultado de %.2f / %.2f es: %.2f\n",numero_Uno,numero_Dos,division);
        }
        else
        {
            printf("c) No es posible dividir por cero\n");
        }

        printf("d) El resultado de %.2f * %.2f es: %.2f\n",numero_Uno,numero_Dos,multiplicacion);

        if(factorial_A != -1 && factorial_B != -1 && flag_validar_numero_entero_A == 1 && flag_validar_numero_entero_B == 1 )
        {
            printf("e) El factorial de %.2f es: %lld y El factorial de %.2f es: %lld\n",numero_Uno,factorial_A,numero_Dos,factorial_B);
        }
        else if(factorial_A == -1 && factorial_B != -1 && flag_validar_numero_entero_B == 1 )
        {
            printf("e) El factorial de %.2f no existe y El factorial de %.2f es: %lld\n",numero_Uno,numero_Dos,factorial_B);
        }
        else if(factorial_A != -1 && factorial_B == -1 && flag_validar_numero_entero_A == 1 )
        {
            printf("e) El factorial de %.2f es: %lld y El factorial de %.2f no existe\n",numero_Uno,factorial_A,numero_Dos);
        }
        else if(factorial_A == -1 && factorial_B == -1 )
        {
            printf("e)No existe el factorial de numeros negativos\n");
        }
        else if(factorial_A != -1 && factorial_B != -1 && flag_validar_numero_entero_A == 1 && flag_validar_numero_entero_B != 1)
        {
            printf("e) El factorial de %.2f es: %lld y El factorial de %.2f no existe\n",numero_Uno,factorial_A,numero_Dos);
        }
        else if(factorial_A != -1 && factorial_B != -1 && flag_validar_numero_entero_A != 1 && flag_validar_numero_entero_B == 1)
        {
            printf("e) El factorial de %.2f no existe y El factorial de %.2f es %lld \n",numero_Uno,numero_Dos,factorial_B);
        }
        else if(factorial_A != -1 && factorial_B != -1 && flag_validar_numero_entero_A != 1 && flag_validar_numero_entero_B != 1)
        {
            printf("e) No existe el factorial de numeros flotantes.\n");
        }
        else{
            printf("e) El factorial de %.2f no existe y El factorial de %.2f no existe\n",numero_Uno,numero_Dos);
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



