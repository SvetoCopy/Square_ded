#include "solver.h"
#ifndef DED_IO_H
#define DED_IO_H

void GetFileValues(const char *filename_inp, Equation inp[]);
Coeffs get_values();
void print_roots(int roots_count, Roots roots);
#endif
