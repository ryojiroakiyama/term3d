#include "term3d.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

char	*string_to_vector(char *content, t_vector *vectors, \
							size_t index, char *end)
{
	char	buf[256];
	int		error;

	error = *content == '\n';
	errno = 0;
	vectors[index].x = strtod(content, &end);
	error |= *end != ',' || errno == ERANGE;
	content = ++end;
	errno = 0;
	vectors[index].y = strtod(content, &end);
	error |= *end != ',' || errno == ERANGE;
	content = ++end;
	errno = 0;
	vectors[index].z = strtod(content, &end);
	error |= *end != '\n' || errno == ERANGE;
	if (error)
	{
		sprintf(buf, "error: line %zu", index + 1);
		exit_with_error(buf);
	}
	return (++end);
}

t_vector	*string_to_vectors(char *content, size_t *vectors_size)
{
	t_vector	*vectors;
	size_t		index;
	char		*end;
	char		*oriaddr;

	oriaddr = content;
	end = NULL;
	*vectors_size = count_new_line(content);
	vectors = malloc(sizeof(*vectors) * *vectors_size);
	if (!vectors)
		exit_with_error(NULL);
	index = 0;
	while (*content)
	{
		content = string_to_vector(content, vectors, index, end);
		++index;
	}
	*vectors_size = index;
	free(oriaddr);
	return (vectors);
}
