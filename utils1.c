#include "term3d.h"
#include <math.h>
#include <stdio.h>

#ifndef M_PI
# define M_PI 3.141592653589793
#endif

double	to_radians(double degrees)
{
	return (degrees * M_PI / 180);
}

t_vector	zero_vector(void)
{
	t_vector	a;

	a.x = 0;
	a.y = 0;
	a.z = 0;
	return (a);
}

static void putoffset(void)
{
	int	cnt;

	cnt = 0;
	while (cnt < OFFSET)
	{
		putchar(' ');
		cnt++;
	}
}

void	putmap(int *put, size_t size)
{
	size_t	i;

	printf("\x1b[H");
	i = 0;
	while (i < size)
	{
		if (i % XMAP == 0)
			putoffset();
		if ((i + 1) % XMAP == 0)
			putchar('\n');
		putchar(" .*#"[put[i]]);
		i++;
	}
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
