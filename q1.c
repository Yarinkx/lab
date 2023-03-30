#include <stdio.h>

/*
 * This program Performs 3 functions:

  1) my_strcmp -This function reciving 2 string and calculates the difference in ASCII  between the  characters
in the same index.

 2) my_strncmp -This function reciving 2 string and number of  characters for comparison .

 3) my_strchr -This function reciving a String and a character,then the function if the character
found in string
 If its exists It will return its index
 if its not it will return a -1.
 */
int my_strcmp(char first[], char second[]);

int my_strncmp(char first[], char second[], int n);

int my_strchr(char str[], char c);

#define z  80

int main() {
    /*Variables for the function my_strcmp */
    char firstCmp[z] = "";
    char secondCmp[z] = "";

    /*Variables for the function my_strncmp */
    char firstNcmp[z] = "";
    char secondNcmp[z] = "";
    char c;

    /*Variables for the function my_strchr */
    char first[z] = "";
    char r;
    int result = 0;

    printf("Test for my_strcmp: \n");
    printf("Eneter 2 String: \n");
    fgets(firstCmp, z, stdin);
    fgets(secondCmp, z, stdin);
    printf("\nThe difference is : %d \n", my_strcmp(firstCmp, secondCmp));

    printf("\nTest for my_strncmp: ");
    printf("\nEnter 2 Stirng: ");
    fgets(firstNcmp, z, stdin);
    fgets(secondNcmp, z, stdin);
    printf("\nEnter how  many characters to check :");
    c = (char) getchar();
    printf("\nThe difference is : '%d' \n", my_strncmp(firstNcmp, secondNcmp, c));

    printf("\nTest for my_strchr: ");
    printf("\nEnter a string: ");
    scanf("%s", first);
    printf("\nEnter What character do u want to find in the string :\n");
    getchar();
    r = getchar();
    result = my_strchr(first, r);
    printf("\nThe index of the character in the string '%s' is :%d\n", first, result);
    return 0;
}

int my_strcmp(char first[], char second[]) {
    int i = 0;
    while (first[i] != '\0' &&
           second[i] != '\0') { /*while loop that running As long as we haven't reached to the end of the strings*/
        if (first[i] == second[i]) { /*if the character in the same location is the same character ,We will move on */
            i++;
        } else { /* If the condition is not happen We will return the difference between the characters*/
            return first[i] - second[i];
        }
    }
    return 0; /*If nothing happens we will return 0*/
}

int my_strncmp(char first[], char second[], int n) {
    int i;
    for (i = 0; i < n; i++) { /*for loop that running from to n (that is the amount of variables to test)*/
        if (first[i] !=
            second[i]) {/*if the character in the same location ist the same character ,We will return the difference  */
            return first[i] - second[i];
        }
        if (second[i] == '\0' &&
            first[i] == '\0') {/*If we have reached the end of the array for both we will return the difference */
            return first[i] - second[i];
        }
    }
    return 0;/*If nothing happens we will return 0*/
}

int my_strchr(char str[], char c) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {/*for loop that going from the beginning of the string to the end of it*/
        if (str[i] ==
            c) {/* Conditions that checks if the character we wanted is in a certain location in the string,If so,we will return its location*/
            return i;
        }
    }
    if (c == '\0') {
        return i;
    }
    return -1;/*If nothing happens we will return -1*/
}