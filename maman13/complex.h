#include <stdio.h>
#include <math.h>

typedef struct complex{
    double real;
    double image;
}complex;

void read_comp(complex *z, double real, double image);
void print_comp(complex *z);
void add_comp(complex *z, complex *b);
void sub_comp(complex *z, complex *b);
void mult_comp_real(complex *z, double num);
void mult_comp_img(complex *z, double img);
void mult_comp_comp(complex *z, complex *b);
void abs_comp(complex *z);