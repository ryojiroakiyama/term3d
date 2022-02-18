#include "term3d.h"
#include <math.h>

#ifndef M_PI
# define M_PI 3.141592653589793
#endif

double	to_radians(double degrees)
{
	return (degrees * M_PI / 180);
}

void	do_matrix(t_vector *v, t_draw *d)
{
	*v = affine(d->matrix4, v);
}

void	mapping(t_vector *v, t_draw *d)
{
	t_vector	tmp;
	int			pixel;

	tmp = affine(d->matrix4, v);
	pixel = convert_to_mapindex(&tmp);
	if (0 <= pixel && pixel <= d->map_size && d->map[pixel] < 3)
		d->map[pixel]++;
}
