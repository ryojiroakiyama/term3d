#include "term3d.h"

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
