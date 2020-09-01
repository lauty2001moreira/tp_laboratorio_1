#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define wait_Time 1

///fijate hasta que numero te permite el long int en la factorizacion.
//void calcularOperaciones(float x , float y);
float sumar( float x , float y);
float restar( float x , float y);
float dividir( float x , float y);
double multiplicar( float x , float y);
int factorizar( int x );
int mostrar_Menu(int opcion, float numero_Uno, float numero_Dos, int flag_Numero_Uno_Ingresado, int flag_Numero_Dos_Ingresado);
void mostrar_operaciones(float numero_Uno,float numero_Dos, float suma ,float resta , float divicion, double multiplicacion, long long int factorial_A,long long int factorial_B,int flag_Operaciones_Calculadas, int flag_validar_numero_entero_A,int flag_validar_numero_entero_B);
int validar_Numero_Entero(float numero);

int main()
{
    int op;
    float suma;
    float resta;
    double multiplicacion;
    float divicion;
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

        op = mostrar_Menu(op,numero_Uno,numero_Dos,flag_Numero_Uno_Ingresado,flag_Numero_Dos_Ingresado);
        switch(op)
        {
            case 1:
                printf("Ingresar 1er operando: ");
                scanf("%f",&numero_Uno);
                flag_Numero_Uno_Ingresado = 1;

                system("clear");
                break;

            case 2:
                printf("Ingresar 2do operando: ");
                scanf("%f",&numero_Dos);
                flag_Numero_Dos_Ingresado = 1;

                system("clear");
                break;

            case 3:
                if(flag_Numero_Uno_Ingresado == 1 && flag_Numero_Dos_Ingresado == 1 )
                {
                    printf("Calculando operaciones....\n");

                    suma = sumar( numero_Uno , numero_Dos );
                    resta = restar( numero_Uno , numero_Dos );
                    divicion = dividir( numero_Uno , numero_Dos );
                    multiplicacion = multiplicar( numero_Uno , numero_Dos );

                    flag_validar_numero_entero_A = validar_Numero_Entero(numero_Uno);
                    if(flag_validar_numero_entero_A ==1)
                    {
                        factorial_A = factorizar( numero_Uno);
                    }

                    flag_validar_numero_entero_B = validar_Numero_Entero(numero_Dos);
                    if(flag_validar_numero_entero_B == 1)
                    {
                        factorial_B = factorizar( numero_Dos );
                    }

                    flag_Operaciones_Calculadas = 1;
                    sleep(wait_Time);
                    system("clear");
                }
                else if(flag_Numero_Uno_Ingresado == 0 && flag_Numero_Dos_Ingresado == 1 )
                {
                    printf("Falta ingresar el primer numero por favor seleccione la opcion uno y ingrese el numero.\n");
                    sleep(wait_Time);
                    system("clear");
                }
                else if(flag_Numero_Uno_Ingresado == 1 && flag_Numero_Dos_Ingresado == 0 )
                {
                    printf("Falta ingresar el segundo numero por favor seleccione la opcion dos y ingrese el numero.\n");
                    sleep(wait_Time);
                    system("clear");
                }
                else
                {
                    printf("Por favor ingrese los numeros antes de continuar.\n");
                    sleep(wait_Time);
                    system("clear");
                }
                break;
            case 4:
                mostrar_operaciones(numero_Uno , numero_Dos, suma , resta , divicion , multiplicacion, factorial_A , factorial_B , flag_Operaciones_Calculadas,flag_validar_numero_entero_A,flag_validar_numero_entero_B);
                break;
            case 5:
                system("clear");
                printf("Hasta luego...");
                break;
            default:
                printf("Por favor ingrese una opcion valida.\n");
                sleep(wait_Time);
                system("clear");
            }

    }while(op != 5);

    return 0;

 }

float sumar( float x , float y){
    float suma;
    suma = x + y;
    return suma;
}

float restar( float x , float y)
{
    float resta;
    resta = x - y;
    return resta;
}
float dividir( float x , float y)
{
    float divicion;
    divicion = x / y;
    return divicion ;
}

double multiplicar( float x , float y)
{
    double multiplicacion;
    multiplicacion = x * y ;
    return multiplicacion;
}

int factorizar( int x )
{
    long long int factorial;
    if(x >= 0)
    {
        if(x == 0)
        {
            factorial = 1;
        }
        else{
            //while( x > 0 )
            //{
            factorial  = x * ( factorizar(x - 1 ) );
            //}
        }
    }
    else
    {
       factorial = -1 ;
    }
    return factorial;
}
int mostrar_Menu(int opcion, float numero_Uno, float numero_Dos, int flag_Numero_Uno_Ingresado, int flag_Numero_Dos_Ingresado)
{
    if(flag_Numero_Uno_Ingresado == 0 && flag_Numero_Dos_Ingresado == 0)
       {
           printf("1-Ingresar 1er operando (A=x).\n2- Ingresar 2do operando (B=y).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5-Salir. \n");
       }
       else if(flag_Numero_Uno_Ingresado == 0 && flag_Numero_Dos_Ingresado !=0 )
       {
           printf("1-Ingresar 1er operando (A=x).\n2- Ingresar 2do operando (B=%.2f).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5-Salir. \n",numero_Dos);
       }
       else if(flag_Numero_Uno_Ingresado == 1 && flag_Numero_Dos_Ingresado == 0 )
       {
           printf("1-Ingresar 1er operando (A=%.2f).\n2- Ingresar 2do operando (B=y).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5-Salir. \n",numero_Uno);
       }
       else
       {
           printf("1-Ingresar 1er operando (A=%.2f).\n2- Ingresar 2do operando (B=%.2f).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5-Salir. \n",numero_Uno,numero_Dos);
       }
    scanf("%d",&opcion);
    return opcion;
}

void mostrar_operaciones(float numero_Uno,float numero_Dos, float suma ,float resta , float divicion, double multiplicacion, long long int factorial_A,long long int factorial_B,int flag_Operaciones_Calculadas, int flag_validar_numero_entero_A, int flag_validar_numero_entero_B)
{
    if(flag_Operaciones_Calculadas == 1)
    {
        //suma
        printf("a) El resultado de %.2f + %.2f es: %.2f\n",numero_Uno,numero_Dos,suma);
        //resta
        printf("b) El resultado de %.2f - %.2f es: %.2f\n",numero_Uno,numero_Dos,resta);
        //divicion.
        if(numero_Dos!=0)
        {
            printf("c) El resultado de %.2f / %.2f es: %.2f\n",numero_Uno,numero_Dos,divicion);
        }
        else
        {
            printf("c) No es posible dividir por cero\n");
        }
        //multiplicacion
        printf("d) El resultado de %.2f * %.2f es: %.2f\n",numero_Uno,numero_Dos,multiplicacion);
        //Errores en la factorizacion.
        ///falta para los numero flotantes. y los numeros mayores de 17
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
        sleep(wait_Time);
        system("clear");
    }

}

int validar_Numero_Entero(float numero)
{
    int aux;
    int flag;//si es 1 es flotante y si es 0 es emtero.
    flag  = 0;
    aux = numero;
    if(numero - aux){
        flag = 0;
    }else{
        flag = 1;
    }
    return flag;
}

