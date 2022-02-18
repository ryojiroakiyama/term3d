#include "term3d.h"

void	iter(t_draw *d, void (*f)(t_vector *v, t_draw *d))
{
	size_t	cnt;

	cnt = 0;
	while (cnt < d->vecs_size)
	{
		f(d->vecs + cnt, d);
		cnt++;
	}
}

void	do_matrix(t_vector *v, t_draw *d)
{
	*v = affine4(d->matrix4, v);
}

void	mapping(t_vector *v, t_draw *d)
{
	t_vector	tmp;
	int			pixel;

	tmp = affine4(d->matrix4, v);
	pixel = convert_to_putindex(&tmp);
	if (0 <= pixel && pixel <= d->size && d->map[pixel] < 3)
		d->map[pixel]++;
}
