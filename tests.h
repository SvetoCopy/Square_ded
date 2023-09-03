//
// Created by Rusal on 03.09.2023.
//

#ifndef DED_TESTS_H
#define DED_TESTS_H
#include "kvadratka.h"

struct TestValue {
    Coeffs TEST_INP{0, 0, 0};
    Roots TEST_RES{0, 0, 0};
};

int TEST_Square(TestValue data, int num);

int TEST_Linear(TestValue data, int num);

void GetFileValues(const char *filename_inp, const char *filename_res, size_t n, TestValue inp[]);

void Test();

#endif //DED_TESTS_H
