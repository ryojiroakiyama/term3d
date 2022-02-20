#include "term3d.h"
#include <string.h>

void	iterate_vectors(t_draw *d, void (*f)(t_vector *v, t_draw *d))
{
	size_t	cnt;

	cnt = 0;
	while (cnt < d->vecs_size)
	{
		f(d->vecs + cnt, d);
		cnt++;
	}
}

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

void	mapping(t_vector *v, t_draw *d)
{
	t_vector	vec_converted;
	int			pixel;

	vec_converted = affine(d->matrix4, v);
	if (convert_to_mapindex(&vec_converted, &pixel) \
		&& d->map[pixel] < (int)(strlen(ASCII) - 1))
		d->map[pixel]++;
}
