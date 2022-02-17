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

typedef struct s_vector {
    double x;
    double y;
    double z;
	size_t len;
}t_vector;

void	putmap(int *put, size_t size)
{
	size_t	i;

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

int	coordinate_to_put(const t_vector *v)
{
	int	xi;
	int	yi;

	xi = (int)(6 * v->x) +(WIDTH / 2);
	yi = (int)(-3 * v->y) + (HEIGHT / 2);
	return yi * WIDTH + xi + OFFSET;
}

void mapping(t_vector v[])
{
	size_t	cnt;
	int		index_put;
	int		put[TOTAL];

	if (!v)
		exit(1);
	bzero(put, sizeof(put));
	cnt = 0;
	while (cnt < v[0].len)
	{
		index_put = coordinate_to_put(v+cnt);
		if (0 <= index_put && index_put <= TOTAL && put[index_put] < 3)
			put[index_put]++;
		cnt++;
	}
	putmap(put, TOTAL);
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
	mapping(v);
}
