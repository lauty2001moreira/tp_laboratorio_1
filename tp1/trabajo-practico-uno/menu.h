
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
int mostrar_Menu( float numero_Uno, float numero_Dos, int flag_Numero_Uno_Ingresado, int flag_Numero_Dos_Ingresado);

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
void mostrar_operaciones(float numero_Uno,float numero_Dos, float suma ,float resta , float division, double multiplicacion, long long int factorial_A,long long int factorial_B,int flag_Operaciones_Calculadas, int flag_validar_numero_entero_A,int flag_validar_numero_entero_B);
