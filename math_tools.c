#include "include/fdf.h"


t_point point_init(float x, float y, float z)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}


float	max(float a, float b)
{
	return (a > b ? a : b);
}

float	mod(float i)
{
	return (i < 0 ? -i : i);
}
