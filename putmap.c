#include "term3d.h"
#include <stdio.h>

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
