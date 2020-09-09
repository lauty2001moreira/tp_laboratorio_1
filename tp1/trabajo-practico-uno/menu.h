
/** \brief muestra el menu de la calculadora con los numeros ingresados por el usuario.
 *
 * \param float el primer numero ingresado por el usuario.
 * \param float el segundo numero ingresado por el usuario.
 * \param int 0 o 1 para saber si el primer numero esta ingresado.
 * \param int 0 o 1 para saber si el segundo numero esta ingresado.
 *
 * \return int la opcion ingresada por el usuario.
 *
 */
int MostrarMenu( float numeroUno, float numeroDos, int , int flagNumeroUnoIngresado);

/** \brief muestra los resultados de las operaciones.
 *
 * \param float el primer numero ingresado por el usuario.
 * \param float el segundo numero ingresado por el usuario.
 * \param float el resultado de la suma.
 * \param float el resultado de la resta.
 * \param float el resultado de la division.
 * \param double el resultado de la multiplicacion.
 * \param long long int el resultado del factorial del primer numero.
 * \param long long int el resultado del factorial del segundo numero.
 * \param int 0 o 1 si las operaciones fueron calculadas.
 * \param int 0 o 1 el primer numero es entero o no.
 * \param int 0 o 1 el segundo numero es entero o no.
 *
 * \return float el resultado de la divicion.
 *
 */
void MostrarOperaciones(float numeroUno,float numeroDos, float suma ,float resta , float division, double multiplicacion, long long int factorialA,long long int factorialB,int flagOperacionesCalculadas, int flagValidarNumeroEnteroA,int flagValidarNumeroEnteroB);
