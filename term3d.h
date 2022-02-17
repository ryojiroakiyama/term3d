#ifndef TERM3D_H
# define TERM3D_H

# include <stddef.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}t_vector;

t_vector	*string_to_vectors(char *content, size_t *vectors_size);
char		*read_file(const char *file_name);
size_t		count_new_line(char *content);
void		exit_with_error(const char *massage);

#endif /* TERM3D_H */
