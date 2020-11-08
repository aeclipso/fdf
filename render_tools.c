#include "include/fdf.h"


int fdf_put_line_to_image(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2;

	while (1)
	{
		fdf_put_pixel_to_image(fdf, x0, y0, fdf->color);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
	return (0);
}


int fdf_put_pixel_to_image(t_fdf *fdf, int x, int y, int color)
{
	unsigned int *dst;


	if (x > fdf->image.w || y > fdf->image.h || x < 0 || y < 0)
	{
		ft_printf("error pixel");
		return (-1);
	}

	dst = (unsigned int *) fdf->image.addr;
	dst[x + (y * fdf->image.line_length / 4)] = color;
	return (0);
}


int fdf_put_background(t_fdf *fdf, int color)
{
	unsigned int size;
	unsigned int i;
	unsigned int *dst;

	i = -1;
	size = fdf->image.h * fdf->image.w;
	dst = (unsigned int *) fdf->image.addr;
	ft_printf("Background on %d pixels\n", size);
	while (size > 0 && ++i != size)
		dst[i] = color;
	ft_printf("Background result is %d\n", i);
	return (0);
}
