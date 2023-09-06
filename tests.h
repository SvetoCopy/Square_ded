#ifndef DED_TESTS_H
#define DED_TESTS_H
#include "solver.h"

struct TestData{
    Coeffs coeffs{ 0, 0, 0 };
    Roots roots{ 0, 0, 0 };
};
int TestSquare(TestData data, size_t num);

void RunAllTests();

#endif //DED_TESTS_H