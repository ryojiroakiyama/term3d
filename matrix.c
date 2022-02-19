#include "term3d.h"
#include <math.h>

#ifndef M_PI
# define M_PI 3.141592653589793
#endif

void	matrix_unit(double matrix[])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 5 == 0)
			matrix[i] = 1;
		else
			matrix[i] = 0;
		i++;
	}
}

static double	to_radians(double degrees)
{
	return (degrees * M_PI / 180);
}

void	matrix_rotate_y(double matrix[])
{
	static int	degrees;
	double		radians;

	radians = to_radians(degrees);
	matrix_unit(matrix);
	matrix[0] = cos(radians);
	matrix[2] = sin(radians);
	matrix[8] = -1 * sin(radians);
	matrix[10] = cos(radians);
	degrees += 10;
}

void	matrix_translate(double matrix[], const double x, \
							const double y, const double z)
{
	matrix_unit(matrix);
	matrix[4 * 0 + 3] = x;
	matrix[4 * 1 + 3] = y;
	matrix[4 * 2 + 3] = z;
}
