#include "term3d.h"

int	convert_to_mapindex(const t_vector *v)
{
	int		xi;
	int		yi;

	xi = (int)(SCALE * ((float)XIMG / YIMG) * v->x) + (XIMG / 2);
	yi = (int)(SCALE * v->y) + (YIMG / 2);
	return (yi * XMAP + xi);
}

static double	calculate_oneline(const double *matrix, const t_vector *v)
{
	return ((matrix[0] * v->x) + (matrix[1] * v->y) \
				+ (matrix[2] * v->z) + matrix[3]);
}

t_vector	affine4(const double matrix[], const t_vector *v)
{
	t_vector	a;

	a.x = calculate_oneline(matrix, v);
	a.y = calculate_oneline(matrix + 4, v);
	a.z = calculate_oneline(matrix + 8, v);
	return (a);
}
