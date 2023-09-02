#include "kvadratka.h"



struct TEST_SQUARE {
    Coeffs TEST_INP[5] = {Coeffs(1, -5, 6),
                          Coeffs(1, 4, 4),
                          Coeffs(1, 2, 5),
                          Coeffs(1, 7, 12),
                          Coeffs(1, 0, 0)};
    Roots TEST_RES[5] = {Roots(2, 3, 2),
                         Roots(-2, 0, 1),
                         Roots(0, 0, 0),
                         Roots(-3, -4, 2),
                         Roots(0, 0, 1),};
    size_t count = 0;
    void TEST() {
        printf("TEST SQUARE\n");
        for (int i = 0; i < 5; ++i) {
            Roots x{0, 0, 0};
            if (TEST_RES[i].count != solve_square(TEST_INP[i], &x)) {
                printf("TEST #%d - FAILED\n", i);
                continue;
            }
            if (is_Equal_Roots(x, TEST_RES[i])){
                printf("TEST #%d - PASSED\n", i);
                count++;
                continue;
            }
            printf("TEST #%d - FAILED\n", i);
        }
        printf("PASSED: %zu\n", count);
        printf("\n");
    }

};

struct TEST_LINEAR {
    Coeffs TEST_INP[5] = {Coeffs(0, 1, 2),
                          Coeffs(0, 4, 4),
                          Coeffs(0, 2, 6),
                          Coeffs(0, 0, 12),
                          Coeffs(0, 0, 0)};
    Roots TEST_RES[5] = {Roots(-2, 0, 1),
                         Roots(-1, 0, 1),
                         Roots(-3, 0, 1),
                         Roots(0, 0, 0),
                         Roots(0, 0, INF_ROOTS),};
    size_t count = 0;
    void TEST() {
        printf("TEST LINEAR\n");
        for (int i = 0; i < 5; ++i) {
            Roots x{0, 0, 0};
            if (TEST_RES[i].count != solve_linear(TEST_INP[i], &x)) {
                printf("TEST #%d - FAILED\n", i);
                continue;
            }
            if (isEqual(x.x1, TEST_RES[i].x1)){
                printf("TEST #%d - PASSED\n", i);
                count++;
                continue;
            }
            printf("TEST #%d - FAILED\n", i);
        }
        printf("PASSED: %zu\n", count);
        printf("\n");
    }


};

