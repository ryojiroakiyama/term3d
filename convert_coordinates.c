#include "term3d.h"

int	convert_to_mapindex(const t_vector *v)
{
	int		xi;
	int		yi;

	xi = (int)(SCALE * ((float)XIMG / YIMG) * v->x) + (XIMG / 2);
	yi = (int)(SCALE * v->y) + (YIMG / 2);
	if (xi < 0 || XIMG < xi)
		return (-1);
	return (yi * XMAP + xi);
}
