#include "term3d.h"

static double	calculate_oneline(const double *matrix, const t_vector *v)
{
	return ((matrix[0] * v->x) + (matrix[1] * v->y) \
				+ (matrix[2] * v->z) + matrix[3]);
}

t_vector	affine(const double matrix[], const t_vector *v)
{
	t_vector	a;

	a.x = calculate_oneline(matrix, v);
	a.y = calculate_oneline(matrix + DIMENSION, v);
	a.z = calculate_oneline(matrix + DIMENSION * 2, v);
	return (a);
}
