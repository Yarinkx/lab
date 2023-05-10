#include <stdio.h>
#include <string.h>
#include <complex.h>
#include <ctype.h>
#include <stdlib.h>

#define INPUT_LEN 1000
#define NUM_FUNC 9
enum names {
    READ_COMP, PRINT_COMP, ADD_COMP, SUB_COMP, MULT_COMP_REAL, MULT_COMP_IMG, MULT_COMP_COMP, ABS_COMP, STOP
};

void remove_Spaces(char *str);

void check_empty(char input[]);

void stop();

int isComplex(char w);

complex *whichComplex(char z);

void inputLine(char line[]);

void check_empty(char line[]);

int firstWord(char *p);

char *skipNum(char *z);

char *skipSpacesAndTabs(char *s);

