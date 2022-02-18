#ifndef TERM3D_H
# define TERM3D_H

#include <stddef.h>

#define WIDTH 80
#define HEIGHT 30
#define SCALE 3
#define OFFSET 0

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct	s_draw
{
	t_vector 	*vecs;
	size_t		vecs_size;
	double		matrix4[16];
	int			size;
	int			map[WIDTH * HEIGHT];
}	t_draw;

t_vector	*string_to_vectors(char *content, size_t *vectors_size);
char		*read_file(const char *file_name);
size_t		count_new_line(char *content);
void		exit_with_error(const char *massage);
int			convert_to_putindex(const t_vector *v);
t_vector	affine4(const double matrix[], const t_vector *v);
void		init_matrix(double matrix[]);
void		matrix_rotate(double matrix[]);
void		matrix_translate(double matrix[], const double x, const double y, const double z);
void		put_matrix(const double matrix[]);
void		put_vectors(t_vector *vecs, size_t vecs_size);
double		to_radians(double degrees);
t_vector	zero_vector(void);
void		putmap(int *put, size_t size);
t_vector	get_average_vectors(const t_vector *v, const size_t size);
void		iter(t_draw *d, void (*f)(t_vector *v, t_draw *d));
void		do_matrix(t_vector *v, t_draw *d);
void		mapping(t_vector *v, t_draw *d);

#endif /* TERM3D_H */
