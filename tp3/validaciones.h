#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/** \brief valida si el mumero es entero o flotante
 *
 * \param float el numero a validar.
 * \return int si 0 es flotante y 1 si es entero.
 *
 */
int ValidarNumeroEntero(float);

/** \brief valida si el mumero es entero o flotante
 *
 * \param float el numero a validar.
 * \return int si 1 es flotante y 0 si es entero.
 *
 */
int ValidarNumeroFlotante(float);

/** \brief valida si el string ingresado es valido
 *
 * \param char* el string a validar.
 *
 *\return int  0 si es valido y 1 si no es valido.
 */
int ValidarString(char*);


/** \brief valida si lo ingresado es un numero entero valido
 *
 * \param char* el numero a validar.
 *
 *\return int  0 si es valido y 1 si no es valido.
 */
int ValidarNumero(char*);

/** \brief valida si lo ingresado es un numero flotante valido
 *
 * \param char* el numero a validar.
 *
 *\return int  0 si es valido y 1 si no es valido.
 */
int ValidarNumeroConComa(char*);
