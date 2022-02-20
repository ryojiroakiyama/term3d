#ifndef TERM3D_H
# define TERM3D_H

# include <stddef.h>

# define W_MAP 61
# define H_MAP 31
# define SCALE 5
# define OFFSET 5
# define DIMENSION 4
# define USLEEP 50000
# define ASCII " .+*$A"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_draw
{
	t_vector	*vecs;
	size_t		vecs_size;
	t_vector	vecs_ave;
	int			map[W_MAP * H_MAP];
	int			map_size;
	double		matrix4[16];
}	t_draw;

t_vector	*string_to_vectors(char *content, size_t *vectors_size);
char		*read_file(const char *file_name);
size_t		count_new_line(char *content);
void		exit_with_error(const char *massage);
int			convert_to_mapindex(const t_vector *v);
t_vector	affine(const double matrix[], const t_vector *v);
void		matrix_unit(double matrix[]);
void		matrix_rotate_y(double matrix[]);
void		matrix_translate(double matrix[], \
							const double x, const double y, const double z);
void		put_matrix(const double matrix[]);
void		put_vectors(t_vector *vecs, size_t vecs_size);
void		put_map(int *put, size_t size);
void		iterate_vectors(t_draw *d, void (*f)(t_vector *v, t_draw *d));
void		get_average(t_vector *v, t_draw *d);
void		do_matrix(t_vector *v, t_draw *d);
void		mapping(t_vector *v, t_draw *d);

#endif /* TERM3D_H */
