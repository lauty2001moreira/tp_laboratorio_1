#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "get.h"
#include "validaciones.h"


/** \brief prints the option menu.
*
* \return void
*
*/
int menu( char * );

/** \brief capitalize the first letter of a word
*
* \param char*
*
* \return 0 - if is all ok.
*
*/
int upperFirtsLetter(char*);

/** \brief prompts the user to press a key to continue the program
*
* \return void
*
*/
void pressAKeyAndClear(void);
