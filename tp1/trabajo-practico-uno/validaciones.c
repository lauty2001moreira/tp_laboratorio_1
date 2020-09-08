
int validar_Numero_Entero(float numero)
{
    int aux;
    int flag;
    flag  = 0;
    aux = numero;
    if(numero - aux){
        flag = 0;
    }else{
        flag = 1;
    }
    return flag;
}

int validar_Numero_Flotante(float numero)
{
    int aux;
    int flag;
    flag  = 0;
    aux = numero;
    if(numero - aux){
        flag = 1;
    }else{
        flag = 0;
    }
    return flag;
}

