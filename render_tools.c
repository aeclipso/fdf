#include "include/fdf.h"


int fdf_put_line_to_image(t_fdf *fdf, t_point *p1, t_point *p2)
{
	float x;
	float y;
	float dx;
	float dy;
	float m;

	x = p1->x;
	y = p1->y;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	m = max(mod(dx), mod(dy));
	dx /= m;
	dy /= m;
	while ((int) (p2->x - x) || (int) (p2->y - y))
	{
		if (!((int) x > fdf->image.w || x < 0 || (int) y > fdf->image.h ||
			  y < 0))
			fdf_put_pixel_to_image(fdf, (int) x, (int) y, fdf->color);
		x += dx;
		y += dy;
	}
	fdf_put_pixel_to_image(fdf, (int) x, (int) y, fdf->color);
	return (0);
}


int fdf_put_pixel_to_image(t_fdf *fdf, int x, int y, int color)
{
	unsigned int *dst;


	if (x > fdf->image.w || y > fdf->image.h || x < 0 || y < 0)
	{
		ft_printf("error pixel");
		exit(1);
		return (0);
	}
//	ft_printf("[fdf_put_pixel_to_image]x = %d; y = %d", x, y);
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
