
/** \brief pide un numero flotante y muestra un mensaje
 *
 * \param char se ingresa un texto .
 * \param char se ingresa un texto que se muestra si hay un error .
 *
 * \return float retorna el numero ingresado.
 *
 */
float GetFloat(char *, char *);

/** \brief pide un numero entero y muestra un mensaje
 *
 * \param char se ingresa un texto .
 * \return float retorna el numero ingresado.
 *
 */
int GetInt(char *, char *);

/** \brief pide un string y lo valida
 *
 * \param char texto a mostrar.
 * \param char texto a mostrar si hay error.
 *
 * \return void
 *
 */
void GetString(char *, char *, char*);


/** \brief pide la confirmacion de una accion
 *
 * \param char texto a mostrar.
 *
 * \return 1 si la confirmacion es 'Y' 0  si diferente  de 'Y'.
 *
 */
int getConfirm(char* text);
