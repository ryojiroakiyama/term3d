#include "term3d.h"
#include <strings.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_draw	draw;

	if (argc != 2)
		exit_with_error("Invalid argument\nusage: ./term3d [3dfile.3d]");
	draw.map_size = W_MAP * H_MAP;
	draw.vecs = string_to_vectors(read_file(argv[1]), &(draw.vecs_size));
	iterate_vectors(&draw, get_average);
	matrix_translate(draw.matrix4, \
		-1 * draw.vecs_ave.x, -1 * draw.vecs_ave.y, -1 * draw.vecs_ave.z);
	iterate_vectors(&draw, do_matrix);
	draw.scale = 4;
	while (1)
	{
		bzero(draw.map, sizeof(draw.map));
		matrix_rotate_y(draw.matrix4);
		iterate_vectors(&draw, mapping);
		put_map(draw.map, draw.map_size);
		usleep(USLEEP);
		key_event(&draw);
	}
	return (0);
}
