#include "tests.h"
#include "io.h"


int main(int argc, const char* argv[]) {
    //runAllTests();
    if (argc <= 1) {
        Coeffs coeffs = GetCoeffs();
        Roots res = { 0, 0, 0 };
        SolveSquare(coeffs, &res);
        PrintRoots(res);
        return 0;
    }
    if (!strcmp(argv[1], "--test")) {
        RunAllTests();
    }
}