#include "term3d.h"
#include <strings.h>
#include <unistd.h>

int main(void)
{
	t_draw		draw;
	t_vector	ave_vecs;

	draw.vecs = string_to_vectors(read_file("./torus.3d"), &(draw.vecs_size));
	ave_vecs = get_average_vectors(draw.vecs, draw.vecs_size);
	matrix_translate(draw.matrix4, -1 * ave_vecs.x, 0, -1 * ave_vecs.z);
	iter(&draw, do_matrix);
	while(1)
	{
		bzero(draw.map, sizeof(draw.map));
		matrix_rotate(draw.matrix4);
		iter(&draw, mapping);
		putmap(draw.map, TOTALBIT);
		usleep(50000);
	}
	//free?
}
