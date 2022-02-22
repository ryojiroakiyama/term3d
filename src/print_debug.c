#include "term3d.h"
#include <stdio.h>

void	put_matrix(const double matrix[])
{
	int	i;

	i = 0;
	while (i < DIMENSION * DIMENSION)
	{
		if (i % DIMENSION == 0)
			printf("\n");
		printf(" %f,", matrix[i]);
		i++;
	}
}

void	put_vectors(t_vector *vecs, size_t vecs_size)
{
	size_t		idx;

	idx = 0;
	while (idx < vecs_size)
	{
		printf("%zu: x: %lf, y: %lf, z: %lf\n", \
				idx, vecs[idx].x, vecs[idx].y, vecs[idx].z);
		idx++;
	}
}
