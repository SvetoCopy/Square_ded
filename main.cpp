#include "tests.h"



int main(int argc, const char* argv[]) {
    if (argc <= 1) {
        Coeffs coeffs = get_values();
        Roots res = {0, 0, 0};
        print_roots(solve_square(coeffs, &res), res);
        return 0;
    }
    if (!strcmp(argv[1], "--test")) {
        runAllTests();
    }
}
