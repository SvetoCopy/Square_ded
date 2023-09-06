#include "solver.h"

int isEqual(double a, double b) {
	return fabs(a - b) < EPSILON;
}

int solve_linear(Coeffs data, Roots* root) {
	assert(root != NULL);

	if (isEqual(data.b, 0)) {
		if (isEqual(data.c, 0)) {
			root->count = INF_ROOTS;
			return INF_ROOTS;
		}
		root->count = NO_ROOTS;
		return NO_ROOTS;
	}

	root->x1 = -data.c / data.b;
	root->x2 = root->x1;
	root->count = 1;
	return ONE_ROOT;
}

int is_Equal_Roots(Roots root_1, Roots root_2) {
	if (((root_1.count == 1) || (root_2.count == 1)) && (root_1.x1 == root_2.x1))
		return 1;
	if ((root_1.x1 == root_2.x1 && root_1.x2 == root_2.x2) || (root_1.x2 == root_2.x1 && root_1.x1 == root_2.x2))
		return 1;
	return 0;
}

// coeffs
int solve_square(Coeffs data, Roots* roots) {
	assert(roots != NULL);

	if (isEqual(data.a, 0)) {
		return solve_linear(data, roots);
	}

	double D = data.b * data.b - 4 * data.a * data.c;

	if (D < 0) {
		roots->count = 0;
		return NO_ROOTS;
	}
	if (isEqual(D, 0)) {
		roots->x1 = -data.b / (2 * data.a);
		roots->x2 = roots->x1;
		roots->count = 1;
		return ONE_ROOT;
	}

	roots->x1 = (-data.b + sqrt(D)) / (2 * data.a);
	roots->x2 = (-data.b - sqrt(D)) / (2 * data.a);
	roots->count = 2;
	return TWO_ROOTS;
}
