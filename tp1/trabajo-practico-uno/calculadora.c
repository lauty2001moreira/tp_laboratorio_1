float Sumar( float x , float y){
    float suma;
    suma = x + y;
    return suma;
}

float Restar( float x , float y)
{
    float resta;
    resta = x - y;
    return resta;
}
float Dividir( float x , float y)
{
    float division;
    division = x / y;
    return division ;
}

double Multiplicar( float x , float y)
{
    double multiplicacion;
    multiplicacion = x * y ;
    return multiplicacion;
}

long long int Factorizar( int x )
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
            factorial  = x * ( Factorizar(x - 1 ) );
        }
    }
    else
    {
        factorial = -1 ;
    }
    return factorial;
}
