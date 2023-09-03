#include "tests.h"

int TEST_Square(TestValue data, size_t num) {
    Roots x{0, 0, 0};
    if (data.TEST_RES.count != solve_square(data.TEST_INP, &x)) {
        printf("TEST #%zu - FAILED\n", num);
        return 0;
    }
    if (is_Equal_Roots(x, data.TEST_RES)) {
        printf("TEST #%zu - PASSED\n", num);
        return 1;
    }
    printf("TEST #%zu - FAILED\n", num);
    return 0;
}

int TEST_Linear(TestValue data, size_t num) {
    Roots x{0, 0, 0};
    if (data.TEST_RES.count != solve_linear(data.TEST_INP, &x)) {
        printf("TEST #%zu - FAILED\n", num);
        return 0;
    }
    if (isEqual(x.x1, data.TEST_RES.x1)) {
        printf("TEST #%zu - PASSED\n", num);
        return 1;
    }
    printf("TEST #%zu - FAILED\n", num);
    return 0;
}

void GetFileValues(const char *filename_inp, const char *filename_res, size_t n, TestValue inp[]) {
    FILE *f_inp;
    f_inp = fopen(filename_inp, "r");
    FILE *f_res = fopen(filename_res, "r");

    assert(f_inp != NULL);
    assert(f_res != NULL);
    size_t i = 0;
    while ((fscanf(f_inp, "%lf, %lf, %lf", &inp[i].TEST_INP.a, &inp[i].TEST_INP.b, &inp[i].TEST_INP.c) != EOF)
           &&
           (fscanf(f_res, "%lf, %lf, %zu", &inp[i].TEST_RES.x1, &inp[i].TEST_RES.x2, &inp[i].TEST_RES.count) != EOF)) {
        i++;
    }

}

void Test() {
    int n = 5;
    TestValue inp_sq[n];
    const char* txt_inp_sq = "inp_square.txt";
    const char* txt_res_sq = "res_square.txt";
    printf("TEST SQUARE\n");
    GetFileValues(txt_inp_sq, txt_res_sq, n, inp_sq);
    size_t count_sq = 0;
    for (size_t i = 0; i < 5; ++i) {
        count_sq += TEST_Square(inp_sq[i], i);
    }
    printf("Count: %zu\n", count_sq);
    printf("\n");
    printf("TEST LINEAR\n");
    TestValue inp_lin[n];
    const char* txt_inp_lin = "inp_linear.txt";
    const char* txt_res_lin = "res_linear.txt";
    GetFileValues(txt_inp_lin, txt_res_lin, n, inp_lin);
    size_t count_lin = 0;
    for (size_t i = 0; i < 5; ++i) {
        count_lin += TEST_Square(inp_lin[i], i);
    }
    printf("Count: %zu\n", count_lin);
}