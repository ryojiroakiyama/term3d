#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 80
#define TOTALBIT (WIDTH * HEIGHT)
#define EYEDISTANCE 20
#define EYETOSCREEN 10

typedef struct s_vector {
    double x;
    double y;
    double z;
}t_vector;

t_vector	zero_vector(void)
{
	t_vector	a;

	a.x = 0;
	a.y = 0;
	a.z = 0;
	return (a);
}

double	max_z(t_vector *v, size_t size)
{
	size_t	index;
	double	z;

	index = 0;
	z = 0;
	while (index < size)
	{
		if (z < v[index].z)
			z = v[index].z;
		index++;
	}
	return z;
}

void	put(char *put, size_t size)
{
	size_t	index;
	double	point;

	index = 0;
	while (index < size)
	{
		point = index % WIDTH;
		if (point == 0)
			putchar('\n');
		else
			putchar(put[index]);
		index++;
	}
}

void mapping(t_vector *v, size_t size)
{
	t_vector	eye;
	t_vector	onscrn;
	size_t		index;
	char		put[TOTALBIT];

	printf("TOTALBIT:%d\n", TOTALBIT);
	eye = zero_vector();
	eye.z = max_z(v, size) + EYEDISTANCE;
	memset(put, ' ', TOTALBIT);
	index = 0;
	while (index < size)
	{
		
		index++;
	}
}
