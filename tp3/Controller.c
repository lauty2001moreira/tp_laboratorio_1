#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int error;
    FILE* pArchivo = fopen(path, "r");

    error = -1;

    if(pArchivo != NULL )
    {
        if(ll_len(pArrayListEmployee) > 0 )
        {

            error = 1;

        }
        else
        {

            if(parser_EmployeeFromText(pArchivo,pArrayListEmployee) != -1)
            {
                error = 0;
            }
        }
    }

    fclose(pArchivo);

    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error;
    FILE* pArchivo = fopen(path, "rb");

    error = -1;

    if(pArchivo != NULL )
    {
        if(ll_len(pArrayListEmployee) > 0 )
        {

            error = 1;

        }
        else
        {

            if(parser_EmployeeFromBinary(pArchivo,pArrayListEmployee) != -1)
            {
                error = 0;
            }
        }
    }

    fclose(pArchivo);
    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error;
    int errorId = 0;
    int errorSueldo = 0;
    int errorHoras = 0;
    int errorNombre = 0;
    int auxHoras;
    int auxSueldo;
    int auxId;
    char auxNombre[21];
    Employee* auxEmploye = NULL;

    error  = -1;

    if(pArrayListEmployee != NULL)
    {
        system("clear");
        printf("---------------------AGREGAR EMPLEADO------------------------");

        error = 0;
        auxEmploye = employee_new();

        if(Employee_askName(auxNombre, "\nIngrese el nombre del nuevo empleado: ", "\nEl nombre solamente debe conener letras, reingrese el nombre del nuevo empleado: ") == 1)
        {


            if(employee_setNombre(auxEmploye, auxNombre) == 0)
            {
                printf("\nNombre ingresado correctamente.");
                errorNombre = 1;

            }
        }

        auxHoras = Employee_askHorasTrabajadas("\n\nIngrese la cantidad de horas trabajadas del nuevo empleado: ", "\nLa cantidad de horas trabajadas solamente debe conener numeros , reingrese La cantidad de horas trabajadas del nuevo empleado: ");

        if( auxHoras >= 0)
        {
            if(employee_setHorasTrabajadas(auxEmploye, auxHoras) == 0)
            {
                printf("\nHoras trabajadas ingresadas correctamente.");
                errorHoras = 1;

            }
        }
        auxSueldo = Employee_askSueldo("\n\nIngrese el sueldo del nuevo empleado: ", "\nEl sueldo solamente debe conener numeros , reingrese el sueldo del nuevo empleado: ") ;

        if(auxSueldo >= 0)
        {
            if(employee_setSueldo(auxEmploye, auxSueldo) == 0)
            {
                printf("\nSueldo ingresado correctamente.");
                errorSueldo = 1;

            }
        }

        auxId = controller_autoincrementalId(pArrayListEmployee);

        if( auxId >= 0 )
        {

            if(employee_setId(auxEmploye, auxId) == 0 )
            {

                errorId = 1;
            }
        }
        if(errorSueldo == 1 && errorHoras == 1 && errorNombre == 1 && errorId == 1)
        {

            ll_add(pArrayListEmployee, auxEmploye);
//            free(auxEmploye);

            error  = 1;
        }
    }

    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int auxId;
    int error;
    Employee* auxEmploye;

    error = -1;

    if(pArrayListEmployee != NULL)
    {
        error = 0;

        controller_ListEmployee(pArrayListEmployee);

        auxId = GetInt("\nIngrese el id del empleado que desea modificar.", "\nError el id solamente debe contener numeros, reingrese el id del empleado que desea modificar." );

        auxEmploye = controller_getElementById(pArrayListEmployee, auxId );

        if(auxEmploye != NULL)
        {
            if(controller_menuEditar( auxEmploye) == 1){
                error = 1;
            }
        }

    }


    return error;
}

int controller_menuEditar(Employee* empleado )
{

    int error;
    int errorNombre = 0;
    int errorSueldo= 0;
    int errorHoras= 0;
    int op;

    error = -1;

    if(empleado != NULL)
    {

        error = 0;
        do
        {
            system("clear");
            printf("---------------------MODIFICAR EMPLEADO------------------------");
            printf("\n     ID\t\t  NOMBRE\tSUELDO\tHORAS TRABAJADAS");
            employee_print(empleado);

//            op = menu("\n\n1-Editar nombre.\n2-Editar horas trabajadas.\n3-Editar sueldo.\n4-Cancelar operacion.\nIngrese una opcion: ");
            op = menu("\n\n1-Editar nombre.\n2-Editar sueldo.\n3-Editar horas trabajadas.\n4-Cancelar operacion.");

            switch(op){

                case 1:
                    errorNombre =  Employee_modifyName(empleado, "\nIngrese el nuevo nombre del empleado: ", "\nError el nombre solamente debe contener letras, reingrese el nuevo nombre del empleado.") ;

                    if(errorNombre == 1)
                    {
                        printf("\nNombre modificado correctamente.");

                    }
                    else
                    {
                    printf("\nHubo un error al modificar el nombre.");
                    }
                    pressAKeyAndClear();
                    break;

                case 2:

                    errorSueldo = Employee_modifySueldo(empleado, "\nIngrese el nuevo sueldo del empleado: ", "\nError el suelddo solamente debe contener numeros, reingrese el nuevo sueldo del empleado.") ;

                    if(errorSueldo == 1)
                    {
                        printf("\nSueldo modificado correctamente.");

                    }
                    else
                    {
                        printf("\nHubo un error al modificar el sueldo.");

                    }
                    pressAKeyAndClear();
                    break;

                case 3:

                    errorHoras = Employee_modifyHorasTrabajadas(empleado, "\nIngrese la nueva cantidad de horas trabajadas del empleado: ", "\nError el suelddo solamente debe contener numeros, reingrese el nuevo sueldo del empleado.") ;

                    if(errorHoras == 1)
                    {
                        printf("\nHoras trabajadas modificada correctamente.");

                    }
                    else
                    {
                        printf("\nHubo un error al modificar las horas trabajadas.");
                    }
                    pressAKeyAndClear();
                    break;

            case 4:

                error = -2;

                break;

            default:

                printf("\nError opcion no valida.");

            }

        }while(op != 4);

        if(errorHoras == 1 && errorNombre == 1 && errorSueldo ==1 )
        {
            error = 1;
        }
    }

    return error;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error;
    int index;
    int auxId;
    int conf;
    Employee* empleado;

    error = -1;

    if(pArrayListEmployee != NULL)
    {
        error = 0;

        controller_ListEmployee(pArrayListEmployee);

        auxId = GetInt("\nIngrese el id del empleado que desea eliminar." , "\nError el id solamente debe contener numeros");

        index = controller_getElementByIdIndex(pArrayListEmployee , auxId);

        if( index != -1){

            empleado = controller_getElementById(pArrayListEmployee , auxId );

            printf("\nEsta seguro que desea eliminar al empleado? ");

            employee_print(empleado);

            conf = getConfirm("\n( Y / N )\n");

            if(conf == 1){

                ll_remove(pArrayListEmployee , index);

                error = 1;

            }

        }else{
            error = -2;
        }

    }

    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int error;
    int len;
    Employee* auxEmploye;

    error = -1;

    if(pArrayListEmployee != NULL)
    {
        system("clear");
        printf("---------------------LISTAR EMPLEADOS------------------------");


        error = 0;
        len = ll_len(pArrayListEmployee) ;

        for ( i = 0 ; i < len ; i++)
        {

            auxEmploye = (Employee*) ll_get(pArrayListEmployee, i);
            employee_print(auxEmploye);
        }

    }
    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int option;
    int orden;

    if(pArrayListEmployee != NULL)
    {
        option = menu("\n1-Ordenar por nombre.\n2-Ordenar por id.\n3-Ordenar por salario.\n4-Ordenar por horas trabajadas.");
        orden = menu("\n0-Orden ascendente.\n1-Orden descendente.");
    }

    switch(option)
    {
    case 1:

        ll_sort(pArrayListEmployee,employee_compareByNombre,orden);
        break;
    case 2:

        ll_sort(pArrayListEmployee,employee_compareById,orden);

        break;
    case 3:

        ll_sort(pArrayListEmployee,employee_compareBySueldo,orden);
        break;
    case 4:

        ll_sort(pArrayListEmployee,employee_compareByHorasTrabajadas, orden);
        break;
    }
    return 1;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error = -1;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[100];
    int len;
    Employee* pEmpleado =  NULL;
    FILE* pArchivo;
    int i;

    pArchivo = fopen(path,"w");

    if(pArchivo !=NULL)
    {
        len = ll_len(pArrayListEmployee);
        error = 0;
        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

        if(pArrayListEmployee != NULL)
        {
            for(i=0;i<len;i++)
            {
                pEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(pEmpleado, &id);
                employee_getHorasTrabajadas(pEmpleado, &horasTrabajadas);
                employee_getNombre(pEmpleado, nombre );
                employee_getSueldo(pEmpleado, &sueldo);

                fprintf(pArchivo,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
            }
            error = 1;
        }
        fclose(pArchivo);

    }else{
        printf("ERRORRERKPAS");

    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error;
    int i;
    int len;
    Employee* auxEmployee;
    FILE* pArchivo;

    error = -1;


    if(pArrayListEmployee != NULL && path != NULL)
    {

        len = ll_len(pArrayListEmployee);
        error = 0;
        pArchivo = fopen( path, "wb");

        if( pArchivo != NULL )
        {

            if(len > 0 )
            {

                for( i = 0 ; i < len ; i++)
                {
                    auxEmployee= (Employee*) ll_get(pArrayListEmployee,i);

                    if(auxEmployee!=NULL)
                    {
                        fwrite(auxEmployee,sizeof(Employee),1,pArchivo);
                    }


                }
                error = 1;
            }
        }
    }
    return error;
}

int controller_autoincrementalId(LinkedList* this)
{

    int error;
    int len;
    int id;
    int* pId = NULL;
    Employee* auxEmploye = NULL;

    error = -1 ;

    if(this != NULL){

        error = 0;
        len = ll_len(this);

        pId = &id;

        auxEmploye = (Employee*) ll_get(this  , len - 1 );

        if(auxEmploye != NULL){
            employee_getId(auxEmploye  , pId);

            id = id + 1;

            error = id;
        }

    }

    return error;
}

Employee* controller_getElementById(LinkedList* this, int id)
{

    //nt error;
    Employee* aux = NULL;
    int index;

    if(this != NULL  && id > 0 )
    {

        index = controller_getElementByIdIndex(this , id);

        aux = ll_get(this, index);

    }

    return aux;
}

int controller_getElementByIdIndex(LinkedList* this, int id)
{
    Employee* aux = NULL;
    int error = -1;
    int i;
    int auxId;

    if(this != NULL && id > 0 )
    {

        for(i = 0 ; i < ll_len(this) ; i++ ){
            aux = ll_get(this  , i);
            employee_getId(aux , &auxId);
            if( id  ==  auxId){
                error = i;

            }

        }

    }

    return error;
}
