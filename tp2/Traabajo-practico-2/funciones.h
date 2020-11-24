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


/** \brief sort a array of numbers in ascendant way
*
*   \param int* array to sort
*
* \return -1 if array is null or the length is < 0 - returns 0 if is all ok
*
*/
int SorArray(int* , int);

/** \brief sort a array of strings in ascendant way
*
*   \param char** array to sort
*
* \return -1 if array is null or the length is < 0 - returns 0 if is all ok
*
*/
int SorArrayOfStrings(char** , int);


