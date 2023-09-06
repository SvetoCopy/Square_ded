#include "tests.h"
#include "io.h"
Coeffs GetCoeffs() {
    Coeffs inp{ 0, 0, 0 };
    printf("Write coefficient of equation in format: 8 9 2\n");
        while (scanf_s("%lg %lg %lg", &inp.a, &inp.b, &inp.c) < 3) {
            printf("Incorrect input!\n");
            while (getchar() != '\n') {}
        }
    return inp;
}

void GetFileValues(const char* filename_inp, TestData inp[]) {
    FILE* f_inp = NULL;
    fopen_s(&f_inp, filename_inp, "r");

    assert(f_inp != NULL);
    size_t i = 0;
    while ((fscanf_s(f_inp, "%lf, %lf, %lf|%lf, %lf, %zu", &inp[i].coeffs.a, &inp[i].coeffs.b,
        &inp[i].coeffs.c, &inp[i].roots.x1, &inp[i].roots.x2, &inp[i].roots.count) != EOF)) {

        i++;
    }

}

void print_roots(Roots roots) {

    switch (roots.count) {
    case INF_ROOTS:
        printf("This equation has infinite number of roots");
        break;
    case NO_ROOTS:
        printf("This equation hasn't roots");
        break;
    case ONE_ROOT:
        printf("This equation has 1 root\nx = %f\n", roots.x1);
        break;
    case TWO_ROOTS:
        printf("This equation has 2 root\nx1 = %f \nx2 = %f", roots.x1, roots.x2);
        break;
    }

}