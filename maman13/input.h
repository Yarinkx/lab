#include <stdio.h>
#include <string.h>
#include <complex.h>
#include <ctype.h>
#include <stdlib.h>

#define INPUT_LEN 1000
#define NUM_FUNC 9
/* numbers to identify the command names */
enum names {
    READ_COMP, PRINT_COMP, ADD_COMP, SUB_COMP, MULT_COMP_REAL, MULT_COMP_IMG, MULT_COMP_COMP, ABS_COMP, STOP
};
/* A function* that removes the white characters */
void remove_Spaces(char *str);

/* A function that gets a pointer to the beginning of the first word in a command and returns a
*number representing the command (or -1 if the first word is not a command) */
void check_empty(char input[]);

/* A function that prints a goodbye message to the user and exits the program */
void stop();

/* A function that receives a character and checks whether he is a name of a complex number (A,B,C,D,E,F) */
int isComplex(char w);

/* A function that accepts one of the characters A, B, C, D, E, F and
 * returns a pointer to the complex number with the same name as the char */
complex *whichComplex(char z);

/* A function that receives an input line and handle it*/
void inputLine(char line[]);

/* A function that gets a pointer to the beginning of the first word*/
int firstWord(char *p);

/*A function that accepts a char pointer (to the beginning of a number) and returns a pointer to the end of the number */
char *skipNum(char *z);

/* A function that receives a string and returns a pointer to the first non-white character in the string */
char *skipSpacesAndTabs(char *s);

