#include "term3d.h"
#include <stdio.h>

static void	putoffset(void)
{
	int	cnt;

	cnt = 0;
	while (cnt < OFFSET)
	{
		putchar(' ');
		cnt++;
	}
}

void	put_map(int *put, size_t size)
{
	size_t	i;

	printf("\x1b[H");
	i = 0;
	while (i < size)
	{
		if (i % W_MAP == 0)
			putoffset();
		putchar(ASCII[put[i]]);
		if ((i + 1) % W_MAP == 0)
			putchar('\n');
		i++;
	}
}
