#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#define WIDTH 50
#define HEIGHT 20
#define TOTAL (WIDTH * HEIGHT)
#define OFFSET 5
# ifndef M_PI
#  define M_PI 3.141592653589793
# endif

typedef struct s_vector {
    double x;
    double y;
    double z;
}t_vector;

typedef struct	s_draw
{
	t_vector 	*vecs;
	double		matrix4[16];
}	t_draw;

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

void	putmap(int *put, size_t size)
{
	size_t	i;

	printf("\x1b[H");
	i = 0;
	while (i < size)
	{
		if (i % WIDTH == 0)
			putchar('\n');
		else
			putchar(" .*#"[put[i]]);
		i++;
	}
	putchar('\n');
}

int	convert_to_putindex(const t_vector *v)
{
	int	xi;
	int	yi;

	xi = (int)(6 * v->x) +(WIDTH / 2);
	yi = (int)(-3 * v->y) + (HEIGHT / 2);
	return yi * WIDTH + xi + OFFSET;
}

static double	calculate(const double *matrix, const t_vector *v)
{
	return ((matrix[0] * v->x) + (matrix[1] * v->y) + (matrix[2] * v->z) + matrix[3]);
}

t_vector	affine4(const double matrix[], const t_vector *v)
{
	t_vector	a;

	a.x = calculate(matrix, v);
	a.y = calculate(matrix + 4, v);
	a.z = calculate(matrix + 8, v);
	a.len = v->len;
	return a;
}

void	init_matrix(double matrix[])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 5 == 0)
			matrix[i] = 1;
		else
			matrix[i] = 0;
		i++;
	}
}

void	put_matrix(const double matrix[])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 4 == 0)
			printf("\n");
		printf(" %f,", matrix[i]);
		i++;
	}
}

t_vector	get_average_vector(t_vector v[])
{
	size_t		index;
	t_vector	ave;

	index = 0;
	ave = zero_vector();
	while (index < v[0].len)
	{
		ave.x += v[index].x;
		ave.y += v[index].y;
		ave.z += v[index].z;
		index++;
	}
	ave.x /= v[0].len;
	ave.y /= v[0].len;
	ave.z /= v[0].len;
	return ave;
}

void	matrix_rotate(double matrix[])
{
	static unsigned int	degrees;
	double				radians;

	radians = to_radians(degrees);
	init_matrix(matrix);
	matrix[0] = cos(radians);
	matrix[2] = sin(radians);
	matrix[8] = -1 * sin(radians);
	matrix[10] = cos(radians);
	degrees += 10;
}

void	matrix_translate(double matrix[], const double x, const double y, const double z)
{
	init_matrix(matrix);
	matrix[4 * 0 + 3] = x;
	matrix[4 * 1 + 3] = y;
	matrix[4 * 2 + 3] = z;
}

void	iter(t_vector *v, double matrix[], int put[], 
				void (*f)(t_vector v[], double m[], int p[]))
{
	size_t cnt;

	cnt = 0;
	while (cnt < v[0].len)
	{
		f(v+cnt, matrix, put);
		cnt++;
	}
}

void	init_coordinate(t_vector *v, double matrix[], int put[])
{
	(void)put;
	*v = affine4(matrix, v);
}

void	mapping(t_vector *v, double matrix[], int put[])
{
	t_vector	tmp;
	int			pixel;

	tmp = affine4(matrix, v);
	pixel = convert_to_putindex(&tmp);
	if (0 <= pixel && pixel <= TOTAL && put[pixel] < 3)
		put[pixel]++;
}

void	start(t_vector v[])
{
	int			index_put;
	int			put[TOTAL];
	double		matrix[16];
	t_vector	ave;

	ave = get_average_vector(v);
	matrix_translate(matrix, -1 * ave.x, 0, -1 * ave.z);
	iter(v, matrix, NULL, init_coordinate);
	while(1)
	{
		bzero(put, sizeof(put));
		matrix_rotate(matrix);
		iter(v, matrix, put, mapping);
		putmap(put, TOTAL);
		usleep(50000);
	}
}

#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void set_vector(t_vector *v, char *s, size_t len)
{
	char **sp = ft_split(s, ',');
	v->x = strtod(sp[0], NULL);
	v->y = strtod(sp[1], NULL);
	v->z = strtod(sp[2], NULL);
	v->len = len;
}

int main(void)
{
	t_vector	v[5000];
	char *line;
	int fd;
	int	sign = 1;
	int cnt = 0;

	fd = open("torus.txt", O_RDONLY);
	while (cnt < 1000)
	{
		cnt++;
		sign = get_next_line(fd, &line);
		set_vector(v+cnt, line, 0);
		free(line);
	}
	close(fd);
	v[0].len = cnt;
	start(v);
}