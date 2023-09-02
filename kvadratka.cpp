
#include "kvadratka.h"

int isEqual(double a, double b) {
	return fabs(a - b) < EPSILON;
}

int solve_linear(Coeffs data, Roots* root) {
    assert(root != NULL);

	if (isEqual(data.b, 0)) {
		return isEqual(data.c, 0) ? INF_ROOTS : NO_ROOTS;
	}

	root->x1 = -data.c / data.b;
	root->x2 = root->x1;
	return ONE_ROOT;
}

int is_Equal_Roots(Roots x, Roots y) {
    if (((x.count == 1)||(y.count == 1))&&(x.x1 == y.x1))
        return 1;
    if ((x.x1 == y.x1 && x.x2 == y.x2) || (x.x2 == y.x1 && x.x1 == y.x2))
        return 1;
    return 0;
}

int solve_square(Coeffs data, Roots* roots) {
	assert(roots != NULL);

	if (isEqual(data.a, 0)) {
		return solve_linear(data, roots);
	}

	double D = data.b * data.b - 4 * data.a * data.c;

	if (D < 0) {
		return NO_ROOTS;
	}
	if (isEqual(D, 0.0)) {
		roots->x1 = -data.b / (2*data.a);
		roots->x2 = roots->x1;
		return ONE_ROOT;
	}

	roots->x1 = (-data.b + sqrt(D)) / (2 * data.a);
	roots->x2 = (-data.b - sqrt(D)) / (2 * data.a);
	return TWO_ROOTS;
}

void print_roots(int roots_count, Roots roots) {

	switch (roots_count) {
	case INF_ROOTS:
		printf("INF");
		break;
	case NO_ROOTS:
		printf("NO ROOTS");
		break;
	case ONE_ROOT:
		printf("x = %f\n", roots.x1);
		break;
	case TWO_ROOTS:
		printf("root.x1 = %f \nx2 = %f", roots.x1, roots.x2);
		break;
	}

}