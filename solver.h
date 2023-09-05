#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

enum NUM_OF_ROOTS {
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3
};
const double EPSILON = 0.000001;

struct Coeffs {
    double a;
    double b;
    double c;
};

struct Roots {
    Roots(double x, double y, size_t c) :
            x1{x}, x2{y}, count{c} {};
    double x1 = 0;
    double x2 = 0;
    size_t count = 0;
};

struct Equation {
    Coeffs coeffs{0, 0, 0};
    Roots roots{0, 0, 0};
};

int isEqual(double a, double b);
int is_Equal_Roots(Roots x, Roots y);
int solve_linear(Coeffs data, Roots *root);
int solve_square(Coeffs data, Roots *roots);



