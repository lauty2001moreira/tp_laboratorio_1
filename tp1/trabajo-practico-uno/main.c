#include <stdio.h>
#include <stdlib.h>
void calcularOperaciones(float x , float y);
float sumar( float x , float y);
float restar( float x , float y);
float dividir( float x , float y);
float multiplicar( float x , float y);
int factorizar( int x );
void mostrarResultados(float suma, float resta, float multiplicacion, float divicion , int factorialA , int factorialB );

int main()
{
    int op;
    float numeroUno ,numeroDos;

    do{
    printf("1-Ingresar 1er operando (A=x).\n2- Ingresar 2do operando (B=y).\n3- Calcular todas las operaciones.\n4- Informar resultados.\n5-Salir. \n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            printf("Ingresar 1er operando ");
            scanf("%f",&numeroUno);
            break;
        case 2:
            printf("Ingresar 2do operando");
            scanf("%f",&numeroDos);
            break;
        case 3:
            calcularOperaciones(numeroUno, numeroDos);
            break;
        case 4:
            void mostrarResultados(void);

    }
    }while(op != 5);
    return 0;
}

void mostrarResultados(float suma, float resta, float multiplicacion, float divicion , int factorialA , int factorialB )
{
    printf("la suma es %.2f.\n",suma);
    printf("la resta es %.2f.\n",resta);
    printf("la divicion es %.2f.\n",divicion);
    printf("la es %.2f\n.",multiplicacion);
    printf("El factorial de A es:%d.\n",factorialA);
    printf("El factorial de B es:%d.\n",factorialB);
}
void calcularOperaciones(float x , float y)
{
    printf("Calculando operaciones....");
    sumar(x , y );
    restar( x , y );
    dividir( x , y );
    multiplicar( x , y );
    factorizar( x );
    factorizar( y );
}
float sumar( float x , float y){
    return (x + y);
}

float restar( float x , float y)
{
    return (x - y);
}
float dividir( float x , float y)
{
    return (x / y) ;
}

float multiplicar( float x , float y)
{
    return (x * y );
}

int factorizar( int x )
{
    int factorial;
    if(x == 0)
    {
        return 1;
    }
    else{
        while( x > 0 )
        {
            return (factorial  = x * ( factorizar(x - 1) ));
        }
    }
}

