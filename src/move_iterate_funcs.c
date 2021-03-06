#include "term3d.h"
#include <string.h>
#include <stdbool.h>

void	get_average(t_vector *v, t_draw *d)
{
	static size_t	cnt;

	d->vecs_ave.x += v->x;
	d->vecs_ave.y += v->y;
	d->vecs_ave.z += v->z;
	cnt++;
	if (cnt == d->vecs_size)
	{
		d->vecs_ave.x /= d->vecs_size;
		d->vecs_ave.y /= d->vecs_size;
		d->vecs_ave.z /= d->vecs_size;
	}
}

void	do_matrix(t_vector *v, t_draw *d)
{
	*v = affine(d->matrix4, v);
}

static double	convert_to_mapindex(const t_vector *v, \
									int *mapindex, double scale)
{
	int		xi;
	int		yi;
	int		xi_max;
	int		yi_max;

	xi_max = W_MAP - 1;
	yi_max = H_MAP - 1;
	xi = (int)((scale * ((float)xi_max / yi_max) * v->x) + (xi_max / 2));
	yi = (int)((scale * v->y) + (yi_max / 2));
	if (xi < 0 || xi_max < xi || yi < 0 || yi_max < yi)
		return (false);
	*mapindex = yi * W_MAP + xi;
	return (true);
}

void	mapping(t_vector *v, t_draw *d)
{
	t_vector	vec_converted;
	int			pixel;

	vec_converted = affine(d->matrix4, v);
	if (convert_to_mapindex(&vec_converted, &pixel, d->scale) \
		&& d->map[pixel] < (int)(strlen(ASCII) - 1))
		d->map[pixel]++;
}
