#include "had.h"

/*
 * A program that will receive the list of values from the user, build the group from them, and finally print
The members of the group in the order of their arrival.And without repetition
 */


int main() {
    int c = 0;
    int *x = NULL;


    printf("Insert numbers by the Enter key (press ctrl-D to stop): ");
    x = get_set(&c);
    set_print(x, c);
    free(x);
    return 0;
}



/* Printing the array that the user entered*/
void printArray(int *a, int size) {
    int i;
    printf("your input is:");
    for (i = 0; i < size; i++) {
        printf(" %d", a[i]);
    }
}

/* A function that receives a pointer to an integer that will return the unique number of elements entered by the user*/
int *get_set(int *pSize) {
    int *p = (int *) calloc(ENLARGE_SIZE, sizeof(int));
    int *q = NULL; /* Define a pointer q to hold the expanded array*/
    int input = 0; /* A variable for the current input value from the user*/
    int i = 0; /* A variable to keep track of the current index in the array*/



    while (scanf("%d", &input) == 1) {/* get input from user*/
        if (i % ENLARGE_SIZE == 0) { /* check if we need to enlarge the array*/
            q = (int *) realloc(p, (i + ENLARGE_SIZE) * sizeof(int));
            p=q;
        }
        if (p == NULL) {/*  check if the  array is NULL*/
            printf("Memory allocation failed.");
            exit(0);
        }
        /* Add the input value to the array*/
        p[i] = input;
        i++;
    }
    printArray(p, i); /* print the array of unique numbers*/
    p = remove_Couples(q, i, pSize);/* A function that receives the array and removes all duplicates from it,
     and returns a pointer to the array with only unique elements*/

    return p;
}

int *remove_Couples(const int *arr, int counter, int *s) {
    int *newArr = (int *) calloc(counter, sizeof(int));/*New Aarr*/
    int j;
    int i;
    int Index = 0; /* Index for the numbers in the new array*/
    int Counter = 0; /* Counter for the number of unique numbers*/

    if (newArr == NULL) {/*  Check if the memory allocation for the new array failed*/
        printf("Error: memory can't be allocated!");
        exit(0); /*  Exit the program*/
    }
    for (i = 0; i < counter; i++) {
        for (j = 0; j < i; j++) {/*  Iterate over all numbers in the original array up to the current number*/
            if (arr[i] == arr[j]) {
                break;/*  If it is, exit the inner loop*/
            }
        }
        if (j == i) {/*  Check if the number was not found in the new array*/
            newArr[Index] = arr[i];/*  Add the number to the new array*/
            Index++;/*  Increment the index for the next number in the new array*/
            Counter++;/*  Increment the counter for the number of unique numbers*/
        }
    }
    *s = Counter; /*  Set the value of the 's' variable to the number of unique numbers*/
    return newArr; /*  Return the new array*/
}

/* Printing the new  array */
void set_print(int *arr, int size) {
    int i;
    printf("\n The new array is  :");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}


