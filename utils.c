#include "term3d.h"
#include <math.h>

#ifndef M_PI
# define M_PI 3.141592653589793
#endif

double	to_radians(double degrees)
{
	return (degrees * M_PI / 180);
}
