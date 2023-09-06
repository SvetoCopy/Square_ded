#ifndef DED_SOLVER
#define DED_SOLVER
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
    double x1;
    double x2;
    size_t count;
};


int isEqual(double a, double b);
int isEqualRoots(Roots x, Roots y);
int SolveLinear(Coeffs data, Roots* root);
int SolveSquare(Coeffs data, Roots* roots);



#endif // !DED_SOLVER
