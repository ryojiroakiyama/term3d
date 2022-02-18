#include "term3d.h"

t_vector	zero_vector(void)
{
	t_vector	a;

	a.x = 0;
	a.y = 0;
	a.z = 0;
	return (a);
}

t_vector	get_average_vectors(const t_vector *v, const size_t size)
{
	size_t		index;
	t_vector	ave;

	index = 0;
	ave = zero_vector();
	while (index < size)
	{
		ave.x += v[index].x;
		ave.y += v[index].y;
		ave.z += v[index].z;
		index++;
	}
	ave.x /= size;
	ave.y /= size;
	ave.z /= size;
	return (ave);
}

void	vecs_iter(t_draw *d, void (*f)(t_vector *v, t_draw *d))
{
	size_t	cnt;

	cnt = 0;
	while (cnt < d->vecs_size)
	{
		f(d->vecs + cnt, d);
		cnt++;
	}
}
