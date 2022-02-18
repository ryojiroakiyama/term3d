#include "term3d.h"
#include <strings.h>
#include <unistd.h>

int	main(void)
{
	t_draw		draw;
	t_vector	ave_vecs;

	draw.map_size = W_MAP * H_MAP;
	draw.vecs = string_to_vectors(read_file("./torus.3d"), &(draw.vecs_size));
	ave_vecs = get_average_vectors(draw.vecs, draw.vecs_size);
	matrix_translate(draw.matrix4, -1 * ave_vecs.x, 0, -1 * ave_vecs.z);
	vecs_iter(&draw, do_matrix);
	while (1)
	{
		bzero(draw.map, sizeof(draw.map));
		matrix_rotate_y(draw.matrix4);
		vecs_iter(&draw, mapping);
		putmap(draw.map, draw.map_size);
		usleep(50000);
	}
}
