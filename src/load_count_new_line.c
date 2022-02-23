#include "term3d.h"

size_t	count_new_line(char *content)
{
	size_t	cnt;

	cnt = 0;
	while (*content)
	{
		if (*content == '\n')
			++cnt;
		++content;
	}
	return (cnt);
}
