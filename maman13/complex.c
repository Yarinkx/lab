#include "complex.h"

void read_comp(complex *z, double real, double image) {
    z->real = real;
    z->image = image;
}


void print_comp(complex *a) {
    printf("%.2f", a->real);
    if (a->image >= 0)
        printf(" + (%2.f)i\n", a->image);
    else
        printf(" - (%2.f)i\n", -a->image);

}


void add_comp(complex *z, complex *b) {
    complex tmp;

    tmp.real = z->real + b->real;
    tmp.image = z->image + b->image;

    print_comp(&tmp);

}


void sub_comp(complex *z, complex *b) {
    complex tmp;

    tmp.real = z->real - b->real;
    tmp.image = z->image - b->image;

    print_comp(&tmp);

}


void mult_comp_real(complex *z, double num) {
    complex tmp;

    tmp.real = z->real * num;
    tmp.image = z->image * num;

    print_comp(&tmp);
}


void mult_comp_img(complex *z, double img) {
    complex tmp;

    tmp.real = -img * (z->image);
    tmp.image = img * z->real;

    print_comp(&tmp);
}


void mult_comp_comp(complex *z, complex *b) {
    complex tmp;

    tmp.real = (z->real * b->real) - (z->image * b->image);
    tmp.image = (z->real * b->image) + (z->image * b->real);

    print_comp(&tmp);
}


void abs_comp(complex *z) {
    printf("%f\n", sqrt(z->real * z->real + z->image * z->image));
}
