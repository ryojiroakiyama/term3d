#include "term3d.h"
#include <stdio.h>

int	main(void)
{
	size_t		len;
	size_t		idx;
	t_vector	*v;

	v = string_to_vectors(read_file("./torus.3d"), &len);
	idx = 0;
	while (idx < len)
		printf("%zu: x: %lf, y: %lf, z: %lf\n", \
		idx++, v[idx].x, v[idx].y, v[idx].z);
}
