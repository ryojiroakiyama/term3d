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
	printf("\n");
}

void	put_vectors(const t_vector *vecs, const size_t vecs_size)
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

void	put_one_vector(const t_vector *v)
{
	printf("x: %lf, y: %lf, z: %lf\n", v->x, v->y, v->z);
}
