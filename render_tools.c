#include "include/fdf.h"

void		create_point(t_fdf *fdf, t_point *point, int x, int y)
{

//	point->z = fdf->matrix[y][x];
//	point->z *= fdf->zoom_z;
//	point->x -= (fdf->width * fdf->zoom) / 2;
//	point->y -= (fdf->height * fdf->zoom) / 2;
//	x_angle(point->x, &(point->y), &(point->z), fdf->angl->x_rot);
//	y_angle(&(point->x), point->y, &(point->z), fdf->angl->y_rot);
//	z_angle(&(point->x), &(point->y), point->z, fdf->angl->z_rot);
	point->x = x;
	point->y = y;
//	point->x += 2;
//	point->y += 2;
	point->x = x * 10;
	point->y = y * 10;

}

void		draw_line(t_fdf *fdf, int x, int y)
{
	t_point	p1;
	t_point	p2;

	create_point(fdf, &p1, x, y);
	if (x < fdf->image.w - 1)
	{
		create_point(fdf, &p2, x + 1, y);
		fdf_put_line_to_image(fdf, &p1, &p2);
	}
	if (y < fdf->image.h - 1)
	{
		create_point(fdf, &p2, x, y + 1);
		fdf_put_line_to_image(fdf, &p1, &p2);
	}
}

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
