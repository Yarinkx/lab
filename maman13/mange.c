
#include "input.h"

/* Macros for common errors: */

#define EXTRANEOUS_TEXT(ch) \
    if (ch) {\
        printf("Extraneous text after end of command\n");\
        return;\
    }

#define MISSING_PARAMETER(ch) \
    if (!ch) {\
        printf("Missing parameter\n");\
        return;\
    }

#define MISSING_COMMA(ch) \
    if (ch != ',') {\
        printf("Missing comma\n");\
        return;\
    }

#define MULTIPLE_CONSECUTIVE_COMMAS(ch) \
    if (ch == ',') {\
        printf("Multiple consecutive commas\n");\
        return;\
    }

/* we need access to these variables in this file */
extern complex A, B, C, D, E, F;

/* an array to easily compare the first word to the command names */
char *commandNames[NUM_FUNC] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real",
                                "mult_comp_img", "mult_comp_comp", "abs_comp", "stop"};

void check_empty(char line[]) {
    printf("Please enter a command:\n"); /* User friendly message */

    /* If there's no line (not even line break character) the
     * program reached the end of the file before receiving stop command */
    if (fgets(line,INPUT_LEN, stdin) == NULL) {
        printf("\nReached EOF before stop command\n");
        exit(0);
    }

    /* print the line the user entered: */
    printf("The line you entered is:\n");
    printf("%s", line);

}

void inputLine(char line[]) {
    int i;
    char *p;
    char *secondNum;

    p = line;

    p = skipSpacesAndTabs(p); /* if there are spaces or tabs at the beginning we ignore them */

    if (p[0] == '\n') { /* check if the line is only with spaces */
        printf("(blank line)\n");
        return;
    }

    i = firstWord(p); /* we classify the command name */
    if (i == -1) {
        printf("Undefined command name\n");
        return;
    }

    p += strlen(commandNames[i]); /* We no longer need the command name */

    remove_Spaces(p); /* In this part of the line we do not need spaces */

    if (p[0] == ',') {
        printf("Illegal comma\n");
        return;
    }


    if (i == STOP) {
        EXTRANEOUS_TEXT(p[0])
        stop(); /* we need to stop the program (the user entered "stop") */
    }

    /* In all the other functions the first variable is A,B,C,D,E,F : */

    MISSING_PARAMETER(p[0])

    if (!isComplex(p[0])) {
        printf("Undefined complex variable\n");
        return;
    }

    /* we now know that p[0] is a complex */

    if (i == ABS_COMP || i == PRINT_COMP) { /* need only one complex name */
        EXTRANEOUS_TEXT(p[1])
        if (i == ABS_COMP)
            abs_comp(whichComplex(p[0]));
        else
            print_comp(whichComplex(p[0]));

        return;
    }

    /* in all the commands we need a comma now: */
    MISSING_COMMA(p[1])

    if (i == ADD_COMP || i == SUB_COMP || i == MULT_COMP_COMP) { /* need 2 complex names (one more) */

        if (!isComplex(p[2])) {  /* There is an error, we will classify it: */
            MISSING_PARAMETER(p[2])

            MULTIPLE_CONSECUTIVE_COMMAS(p[2])

            printf("Undefined complex variable\n");
            return;
        }

        /* p[2] is the name of the second complex parameter */

        EXTRANEOUS_TEXT(p[3])

        /* All right! */

        if (i == ADD_COMP)
            add_comp(whichComplex(p[0]), whichComplex(p[2]));
        else if (i == SUB_COMP)
            sub_comp(whichComplex(p[0]), whichComplex(p[2]));
        else
            mult_comp_comp(whichComplex(p[0]), whichComplex(p[2]));

        return;
    }

    /* we now know that i is READ_COMP or MULT_COMP_REAL or MULT_COMP_IMG (so we need a first number for all of them:)*/

    if (!isdigit(p[2])) { /* the parameter may not be a number */
        MISSING_PARAMETER(p[2])

        MULTIPLE_CONSECUTIVE_COMMAS(p[2])

        if (p[2] != '-' || !isdigit(p[3])) { /* check for negative number */
            printf("Invalid parameter - not a number\n");
            return;
        }
    }

    /* we now know that there is a first number */

    if (i == READ_COMP) { /* we need one more comma and one more number */
        secondNum = skipNum(p + 2);

        MISSING_COMMA(*secondNum)

        secondNum += 1; /* we want it on the first digit of the number */

        if (!isdigit(secondNum[0])) { /* the parameter may not be a number */

            MISSING_PARAMETER(secondNum[0])

            MULTIPLE_CONSECUTIVE_COMMAS(secondNum[0])

            if (secondNum[0] != '-' || !isdigit(secondNum[1])) { /* check for negative number */
                printf("Invalid parameter - not a number\n");
                return;
            }

        }
        /* we now know that there are 2 numbers in the line */

        EXTRANEOUS_TEXT(*skipNum(secondNum)) /* check for extraneous text after the second number */

        /* All right! */
        read_comp(whichComplex(p[0]), atof(p + 2), atof(secondNum));
        return;
    }

    EXTRANEOUS_TEXT(*skipNum(p + 2))

    /* All right! */
    if (i == MULT_COMP_REAL)
        mult_comp_real(whichComplex(p[0]), atof(p + 2));
    else /* i = MULT_COMP_IMG */
        mult_comp_img(whichComplex(p[0]), atof(p + 2));

}

void stop() {
    printf("You finished using my program,\nI hope you enjoyed!"); /* goodbye message :) */
    exit(0);
}

int firstWord(char *p) {
    int i;
    int count = 0;

    for (i = 0; p[i] && p[i] != ' ' && p[i] != '\t' && p[i] != ',' && p[i] != '\n'; i++) {
        count++; /* we count how many characters the first word have */
    }

    for (i = 0; i < NUM_FUNC; i++) { /* we compare the first word with each of the command names */
        if (strlen(commandNames[i]) == count && !strncmp(commandNames[i], p, count)) /* equals */
            return i;
    }
    return -1; /* the command name is not good */

}

char *skipSpacesAndTabs(char *s) {
    int n;
    for (n = 0; s[n] != 0 && (s[n] == ' ' || s[n] == '\t'); n++) {} /* Count how many spaces there are at the beginning */
    return s + n;
}


complex *whichComplex(char x) {
    /* returning a pointer to the complex number with the same name as the char */
    if (x == 'A')
        return &A;
    if (x == 'B')
        return &B;
    if (x == 'C')
        return &C;
    if (x == 'D')
        return &D;
    if (x == 'E')
        return &E;
    if (x == 'F')
        return &F;

    return NULL; /* never reaches hear */
}

int isComplex(char x) {
    return x >= 'A' && x <= 'F'; /* complex name in only A,B,C,D,E,F */
}


/* Function to remove all spaces from a given string */
void remove_Spaces(char *str) {
    int i;
    /* To keep track of non-space character count */
    int count = 0;

    /* Traverse the given string. If current character
     is not space, then place it at index 'count++' */
    for (i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            str[count++] = str[i]; /* here count is incremented */
    }

    str[count] = '\0'; /* finish the string */
}

char *skipNum(char *s) {
    int i = 0;
    int hadDot = 0;

    if (s[0] == '-')
        i++; /* skip the - sign at the beginning of the number (if there is one) */

    for (; isdigit(s[i]) || s[i] == '.'; i++) {
        if (s[i] == '.') {
            if (hadDot || !isdigit(s[i + 1])) /* the dot is the end of the number */
                return s + i;
            hadDot = 1; /* only one dot is allowed in the number */
        }
    }
    return s + i; /* return a pointer to the char after the number */

}

