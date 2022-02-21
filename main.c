#include "term3d.h"
#include <strings.h>
#include <unistd.h>

int	main(void)
{
	t_draw		draw;

	draw.map_size = W_MAP * H_MAP;
	draw.scale = 1;
	draw.vecs = string_to_vectors(read_file("./torus.3d"), &(draw.vecs_size));
	iterate_vectors(&draw, get_average);
	matrix_translate(draw.matrix4, \
					-1 * draw.vecs_ave.x, 0, -1 * draw.vecs_ave.z);
	iterate_vectors(&draw, do_matrix);
	while (1)
	{
		bzero(draw.map, sizeof(draw.map));
		matrix_rotate_y(draw.matrix4);
		draw.scale = 4;
		iterate_vectors(&draw, mapping);
		put_map(draw.map, draw.map_size);
		usleep(USLEEP);
	}
}
