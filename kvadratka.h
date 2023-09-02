// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
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
    Coeffs(double a1, double b1, double c1) :
            a{a1}, b{b1}, c{c1} {};
    double a = 0;
    double b = 0;
    double c = 0;
};

struct Roots {
    Roots(double x, double y, size_t c) :
            x1{x}, x2{y}, count{c} {};
    double x1 = 0;
    double x2 = 0;
    size_t count = 0;
};

int isEqual(double a, double b);
int is_Equal_Roots(Roots x, Roots y);
int solve_linear(Coeffs data, Roots *root);

int solve_square(Coeffs data, Roots *roots);

void print_roots(int roots_count, Roots roots);

