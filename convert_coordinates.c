#include "term3d.h"

int	convert_to_mapindex(const t_vector *v)
{
	int		xi;
	int		yi;
	int		xi_max;
	int		yi_max;

	xi_max = W_MAP - 1;
	yi_max = H_MAP - 1;
	xi = (int)(SCALE * ((float)xi_max / yi_max) * v->x) + (xi_max / 2);
	yi = (int)(SCALE * v->y) + (yi_max / 2);
	if (xi < 0 || xi_max < xi)
		return (-1);
	return (yi * W_MAP + xi);
}
