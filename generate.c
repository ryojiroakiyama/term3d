#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#define WIDTHBIT 60
#define HEIGHTBIT 20
#define TOTALBIT (WIDTHBIT * HEIGHTBIT)
#define OFFSETBIT 5

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
		if (i % WIDTHBIT == 0)
			putchar('\n');
		else
			putchar(" .*#"[put[i]]);
		i++;
	}
	putchar('\n');
}

int	convert(const t_vector *v)
{
	int	xi;
	int	yi;

	xi = (int)(6 * v->x) +(WIDTHBIT / 2);
	yi = (int)(-3 * v->y) + (HEIGHTBIT / 2);
	return yi * WIDTHBIT + xi + OFFSETBIT;
}

void mapping(t_vector v[])
{
	size_t	i;
	int		point;
	int		put[TOTALBIT];

	if (!v)
		exit(1);
	bzero(put, sizeof(put));
	i = 0;
	while (i < v[0].len)
	{
		point = convert(v+i);
		if (0 <= point && point <= TOTALBIT && put[point] < 3)
			put[point]++;
		i++;
	}
	putmap(put, TOTALBIT);
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
