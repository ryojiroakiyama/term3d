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
	t_vector	tmp;
	int			pixel;

	tmp = affine(d->matrix4, v);
	pixel = convert_to_mapindex(&tmp);
	if (0 <= pixel && pixel <= d->map_size && (size_t)d->map[pixel] < strlen(ASCII) - 1)
		d->map[pixel]++;
}
