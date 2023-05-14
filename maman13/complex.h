#include <stdio.h>
#include <math.h>
/*  complex  struct */
typedef struct complex{
    double real;
    double image;
}complex;

/*A function that places values in a complex variable*/
void read_comp(complex *z, double real, double image);

/*A function that prints a complex number*/
void print_comp(complex *z);

/* A function that receives 2 complex and sums them up and prints the reslut  */
void add_comp(complex *z, complex *b);

/*A function that receives two complex numbers as parameters, subtracts them and prints the result*/
void sub_comp(complex *z, complex *b);

/*A function that calculates the multiplication of a complex number and a real number*/
void mult_comp_real(complex *z, double num);

/*A function that calculates the multiplication of a complex number and an imaginary number*/
void mult_comp_img(complex *z, double img);

/*A function that calculates the multiplication */
void mult_comp_comp(complex *z, complex *b);

/*A function that calculates the absolute value */
void abs_comp(complex *z);