#include "tests.h"

int TestSquare(Equation data, size_t num) {
    Roots x{0, 0, 0};
    if (data.roots.count != solve_square(data.coeffs, &x)) {
        printf("TEST #%zu - FAILED (Different count of roots)\n", num);
        return 0;
    }
    if (is_Equal_Roots(x, data.roots)) {
        printf("TEST #%zu - PASSED\n", num);
        return 1;
    }
    printf("TEST #%zu - FAILED (Different roots)\n", num);
    return 0;
}



void runAllTests() {
    const int n = 10;
    Equation inp_sq[n] = {};
    const char* txt_inp_sq = "inp_square.txt";

    printf("TEST SQUARE\n");

    GetFileValues(txt_inp_sq, inp_sq);
    size_t n_success = 0;
    for (size_t i = 0; i < n; ++i) {
        n_success += TestSquare(inp_sq[i], i);
    }

    printf("Count: %zu\n", n_success);
}