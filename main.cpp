#include "tests.h"
#include "io.h"


int main(int argc, const char* argv[]) {
    //runAllTests();
    if (argc <= 1) {
        Coeffs coeffs = get_values();
        Roots res = { 0, 0, 0 };
        solve_square(coeffs, &res);
        print_roots(res);
        return 0;
    }
    if (!strcmp(argv[1], "--test")) {
        runAllTests();
    }
}