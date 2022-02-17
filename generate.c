#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define WIDTHBIT 60
#define HEIGHTBIT 20
#define TOTALBIT (WIDTHBIT * HEIGHTBIT)
#define EYEDISTANCE 20
#define EYETOSCREEN 10

typedef struct s_vector {
    double x;
    double y;
    double z;
}t_vector;

void	putmap(char *put, size_t size)
{
	size_t	index;
	double	point;

	index = 0;
	while (index < size)
	{
		point = index % WIDTHBIT;
		if (point == 0)
			putchar('\n');
		else
			putchar(put[index]);
		index++;
	}
	putchar('\n');
}

void	section(void)
{
	int j = 0;
	while (j < 20)
	{
		int i = 0;
		while (i < 60)
		{
			if (i < 10)
				putchar(' ');
			else
				putchar('.');
			i++;
		}
		putchar('\n');
		j++;
	}
}

void mapping(t_vector *v, size_t size)
{
	int		xi;
	int		yi;
	size_t	index_v;
	char	put[TOTALBIT];

	printf("TOTALBIT:%d\n", TOTALBIT);
	memset(put, '.', TOTALBIT);
	putmap(put, TOTALBIT);
}

int main(void)
{
	section();
	mapping(NULL, 0);
}
