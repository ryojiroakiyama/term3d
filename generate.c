#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#define WIDTHBIT 60
#define HEIGHTBIT 20
#define TOTALBIT (WIDTHBIT * HEIGHTBIT)
#define OFFSETBIT 10

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
			putchar(put[i] + '0');
		i++;
	}
	putchar('\n');
}

void	section(void)
{
	int j = 0;
	while (j < 20)
	{
		int i = 0;
		while (i < 10)
		{
			putchar(' ');
			i++;
		}
		while (i < 60)
		{
			putchar('.');
			i++;
		}
		putchar('\n');
		j++;
	}
}

int	convert(const t_vector *v)
{
	int	xi;
	int	yi;

	//printf("x:%f, y%f\n", v->x, v->y);
	xi = (int)(5 * v->x) +(WIDTHBIT / 2);
	yi = (int)(-1 * v->y) + (HEIGHTBIT / 2);
	//printf("xi:%d, yi%d\n", xi, yi);
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
		if (0 <= point && point <= TOTALBIT && put[point] < 9)
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
	//section();
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
	//set_vector(v, "0.544456534909866,2.5718969675658103,5", 3);
	//set_vector(v+1, "3.761971793423513,-3.4237940770708266,5.143797326596529", 3);
	//set_vector(v+2, "1.9618820122077107,0.251473437357552,5.2861578778387805", 3);
	v[0].len = cnt;
	mapping(v);
}
