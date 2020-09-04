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
    float division;
    division = x / y;
    return division ;
}

double multiplicar( float x , float y)
{
    double multiplicacion;
    multiplicacion = x * y ;
    return multiplicacion;
}

long long int factorizar( int x )
{
    long long int factorial;
    if(x >= 0)
    {
        if(x == 0)
        {
            factorial = 1;
        }
        else
        {
            factorial  = x * ( factorizar(x - 1 ) );
        }
    }
    else
    {
        factorial = -1 ;
    }
    return factorial;
}
