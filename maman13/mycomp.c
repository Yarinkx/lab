
/* A program that receives commands about complex numbers from the user and executes them.
 * author: Elad Shoshani */

#include "input.h"
/* A function that initializes the complex variables to a value of 0 + 0i */
void initialize();

/* A function that performs the entire process of the program and the user interaction (of course using other functions) */
void program_process(char line[]);

complex A, B, C, D, E, F;

/* The main method: */
int main() {
    char line[INPUT_LEN];
    initialize(); /* Initialize the complex variables to a value of 0 + 0i */
    program_process(line);
    return 0;
}


void initialize() {
    read_comp(&A, 0, 0);
    read_comp(&B, 0, 0);
    read_comp(&C, 0, 0);
    read_comp(&D, 0, 0);
    read_comp(&E, 0, 0);
    read_comp(&F, 0, 0);
}


void program_process(char line[]) {
    while (1) { /* Until the stop command or the end of the file (there is an exit function) */
         check_empty(line); /* get the input line the user entered */
        inputLine(line); /* handle the line the user entered */
    }
}

