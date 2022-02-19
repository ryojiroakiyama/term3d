#include "term3d.h"
#include <strings.h>
#include <unistd.h>

int	main(void)
{
	t_draw		draw;

	draw.map_size = W_MAP * H_MAP;
	draw.vecs = string_to_vectors(read_file("./torus.3d"), &(draw.vecs_size));
	iterate_vecs(&draw, average_vecs);
	matrix_translate(draw.matrix4, \
					-1 * draw.vecs_ave.x, 0, -1 * draw.vecs_ave.z);
	iterate_vecs(&draw, do_matrix);
	while (1)
	{
		bzero(draw.map, sizeof(draw.map));
		matrix_rotate_y(draw.matrix4);
		iterate_vecs(&draw, mapping);
		putmap(draw.map, draw.map_size);
		usleep(50000);
	}
}
