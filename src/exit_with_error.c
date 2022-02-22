#include "term3d.h"
#include <stdlib.h>
#include <stdio.h>

void	exit_with_error(const char *massage)
{
	if (massage)
		fprintf(stderr, "%s\n", massage);
	else
		perror("error: ");
	exit(EXIT_FAILURE);
}
