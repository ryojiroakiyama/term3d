#include "term3d.h"
#include <math.h>

void	init_matrix(double matrix[])
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

void	matrix_rotate(double matrix[])
{
	static unsigned int	degrees;
	double				radians;

	radians = to_radians(degrees);
	init_matrix(matrix);
	matrix[0] = cos(radians);
	matrix[2] = sin(radians);
	matrix[8] = -1 * sin(radians);
	matrix[10] = cos(radians);
	degrees += 10;
}

void	matrix_translate(double matrix[], const double x, \
							const double y, const double z)
{
	init_matrix(matrix);
	matrix[4 * 0 + 3] = x;
	matrix[4 * 1 + 3] = y;
	matrix[4 * 2 + 3] = z;
}
