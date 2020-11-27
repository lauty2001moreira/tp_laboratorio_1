#include "Employee.h"

Employee* employee_new()
{
    Employee* pEmpleado;

    pEmpleado = (Employee*) malloc(sizeof(Employee));


    if(pEmpleado!= NULL )
    {
        employee_setId(pEmpleado , -1);
        employee_setNombre(pEmpleado , '\0');
        employee_setHorasTrabajadas(pEmpleado , 0);
        employee_setSueldo(pEmpleado , 0);
    }

    return pEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* pEmpleado;
    int id;
    int horasTrabajadas;

    pEmpleado = employee_new();

    if(pEmpleado!=NULL)
    {

        id = atoi(idStr);
        employee_setId(pEmpleado , id);

        employee_setNombre(pEmpleado, nombreStr);//FALTA VERIFICAR SETTRERS

        horasTrabajadas = atoi(horasTrabajadasStr);
        employee_setHorasTrabajadas(pEmpleado , horasTrabajadas);

    }
    return pEmpleado;
}


//void employee_delete(Employee* this)
//{
//    int error;
//    int* auxId;
//
//    error = -1;
//
//    if( this != NULL)
//    {
//        error = 0;
//
//        employee_getId(this , auxId);
//
//        ll_remove(this , );
//
//    }
//
//}


int employee_setId(Employee* this,int id)
{

    int error;
    error = -1;

    if( this != NULL && id > 0)
    {

        this->id = id;
        error = 0;
    }

    return error;
}

int employee_getId(Employee* this, int* id)
{

    int error;
    error = -1;

    if(this != NULL && id != NULL)
    {

        *id = this->id ;
        error = 0;
    }
    return error;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int error;
    error = -1;

    if( this != NULL && nombre != NULL)
    {

        strcpy(this->nombre, nombre);

        error = 0;
    }
    return error;
}
int employee_getNombre(Employee* this,char* nombre){

    int error;
    error = -1;

    if( this != NULL && nombre != NULL)
    {
        strcpy( nombre , this->nombre );

        error = 0;
    }
    return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int error;
    error = -1;

    if( this != NULL && horasTrabajadas > 0)
    {

        this->horasTrabajadas = horasTrabajadas;

        error = 0;
    }

    return error;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int error;
    error = -1;

    if( this != NULL && horasTrabajadas != NULL)
    {

        *horasTrabajadas = this->horasTrabajadas ;
        error = 0;
    }

    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{

    int error;
    error = -1;

    if( this != NULL && sueldo > 0)
    {

        this->sueldo = sueldo;
        error = 0;
    }

    return error;
}
int employee_getSueldo(Employee* this,int* sueldo)
{

    int error;
    error = -1;

    if( this != NULL  )
    {

        *sueldo = this->sueldo ;
        error = 0;
    }

    return error;
}
int employee_print(Employee* this){

    int error;
    int id;
    int salario;
    int horasTrabajadas;
    char nombre[100];

    error = -1;

    if(this != NULL){

        error = 0;

        employee_getId(this , &id);
        employee_getSueldo(this , &salario);
        employee_getHorasTrabajadas(this , &horasTrabajadas);
        employee_getNombre(this , nombre);

        printf("\n%9d%15s%10d%10d", id , nombre , salario , horasTrabajadas);
    }
    return error;
}

int Employee_askName(char* nombre , char* text ,char* errorText){

    int error;

    error = -1;

    if(nombre!= NULL){

        error = 0;

        if(GetStringName(text , errorText , nombre) == 1){
            error = 1;
        }
    }

    return error;
}

int Employee_askHorasTrabajadas( char* text ,char* errorText){

    int error;
    int auxHoras;

    error = -1;

    if(text != NULL && errorText != NULL){

        error = 0;

        auxHoras = GetInt( text , errorText );

        if( auxHoras >= 0){

            error = auxHoras ;

        }
    }

    return error;
}
int Employee_askSueldo( char* text ,char* errorText){

    int error;
    int auxSueldo;

    error = -1;

    if(text != NULL && errorText != NULL){

        error = 0;

        auxSueldo = GetInt( text , errorText );

        if( auxSueldo >= 0){

            error = auxSueldo;

        }
    }

    return error;
}

int Employee_modifyName(Employee* empleado  , char* text , char* errorText ){

    int error;
    char auxName[21];

    error = -1;

    if(empleado != NULL){
        error = 0;

        if(Employee_askName(auxName , text  , errorText ) == 1 ){

            if(employee_setNombre(empleado  , auxName)  == 0){

                error = 1;
            }

        }

    }
    return error;
}

int Employee_modifySueldo(Employee* empleado  , char* text , char* errorText ){

    int error;
    int auxSueldo;

    error = -1;

    if(empleado != NULL){
        error = 0;

        auxSueldo = Employee_askSueldo(text  , errorText );

        if( auxSueldo >= 0 ){

            if(employee_setSueldo(empleado  , auxSueldo)  == 0){

                error = 1;
            }

        }

    }
    return error;
}


int Employee_modifyHorasTrabajadas(Employee* empleado  , char* text , char* errorText ){

    int error;
    int auxHoras;

    error = -1;

    if(empleado != NULL){
        error = 0;

        auxHoras = Employee_askHorasTrabajadas(text  , errorText );

        if( auxHoras >= 0 ){

            if(employee_setHorasTrabajadas(empleado  , auxHoras)  == 0){

                error = 1;
            }

        }

    }
    return error;
}
int employee_compareById(void* this ,void* this2)
{
    int resultado;
    Employee* empleado1 = NULL;
    Employee* empleado2 = NULL;
    int idA;
    int idB;

    if(this !=NULL && this2 !=NULL)
    {
        empleado1 = (Employee*) this;
        empleado2 = (Employee*) this2;

        employee_getId(empleado1,&idA);
        employee_getId(empleado2,&idB);

        if( idA > idB)
        {
            resultado = 1;
        }
        else if(idA == idB)
        {
            resultado = 0;
        }
        else{
            resultado = -1;
        }
    }
    return resultado;
}
int employee_compareByNombre(void* this ,void* this2)
{
    int resultado;

    char nombre[51];
    char nombre2[51];
    Employee* empleado1 = NULL;
    Employee* empleado2 = NULL;

    if(this != NULL && this2 !=NULL)
    {
        empleado1 = (Employee*) this;
        empleado2 = (Employee*) this2;

        employee_getNombre(empleado1, nombre);
        employee_getNombre(empleado2, nombre2);

        resultado = strcmp(nombre,nombre2);
        printf("\nRresultado cmp %d",resultado);
    }
    return resultado;
}
int employee_compareByHorasTrabajadas(void* this ,void* this2)
{
    int resultado;
    Employee* empleado1 = NULL;
    Employee* empleado2 = NULL;
    int horasTrabajadas;
    int horasTrabajadas2;

    if(this != NULL && this2 !=NULL)
    {

        empleado1 = (Employee*) this;
        empleado2 = (Employee*) this2;

        employee_getHorasTrabajadas(empleado1, &horasTrabajadas);
        employee_getHorasTrabajadas(empleado2, &horasTrabajadas2);

        if(horasTrabajadas > horasTrabajadas2)
        {
            resultado = 1;
        }
        else if(horasTrabajadas == horasTrabajadas2)
        {
            resultado = 0;
        }
        else
        {
            resultado = -1;
        }

    }

    return resultado;

}
int employee_compareBySueldo(void* this ,void* this2){


    int resultado;
    Employee* empleado1 = NULL;
    Employee* empleado2 = NULL;
    int sueldo1;
    int sueldo2;

    if(this !=NULL && this2 !=NULL)
    {

        empleado1 = (Employee*) this;
        empleado2 = (Employee*) this2;

        employee_getSueldo(empleado1, &sueldo1);
        employee_getSueldo(empleado2, &sueldo2);

        if(sueldo1 > sueldo2)
        {
            resultado = 1;
        }
        else if(sueldo1 == sueldo2)
        {
            resultado = 0;
        }
        else
        {
            resultado = -1;
        }
    }
    return resultado;
}
