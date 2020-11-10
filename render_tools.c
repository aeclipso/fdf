#include "include/fdf.h"

void create_point(t_fdf *fdf, t_point *point, int x, int y)
{
	// float x_rot = -3.834442f;
	// float z_rot = -2.534443f;
	// float y_rot = -2.614443f;
	// float x_rot = -90.0 * M_PI / 360;
	// float z_rot = 0.0;
	// float y_rot = 1.0;
	point->x = 0;
	point->y = 0;
	point->z = 0;

	point->x = x * fdf->section;
	point->y = y * fdf->section;
	point->z = fdf->map->map[y][x];
	point->color = (point->z) ? 1 : 0;
	point->x -= (fdf->map->width * fdf->section) / 2;
	point->y -= (fdf->map->height * fdf->section) / 2;
	point->z *= fdf->section;
	x_angle(point->x, &(point->y), &(point->z), fdf->x_r);
	y_angle(&(point->x), point->y, &(point->z), fdf->y_r);
	z_angle(&(point->x), &(point->y), point->z, fdf->z_r);
	point->x += W_WIDTH / 2;
	point->y += W_HEIGHT / 2;


}

void draw_line(t_fdf *fdf, int x, int y)
{
	t_point p1;
	t_point p2;

	create_point(fdf, &p1, x, y);
	if (x < fdf->map->width - 1)
	{
		create_point(fdf, &p2, x + 1, y);
		fdf_put_line_to_image(fdf, &p1, &p2);
	}
	if (y < fdf->map->height - 1)
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
		if (!((int) x > fdf->image.w || x < 0 || (int) y > fdf->image.h || y < 0))
		{
			if (p1->color || p2->color)
				fdf_put_pixel_to_image(fdf, (int) x, (int) y, fdf->color1);
			else
				fdf_put_pixel_to_image(fdf, (int) x, (int) y, fdf->color2);
		}
		x += dx;
		y += dy;
	}
	if (p1->color || p2->color)
		fdf_put_pixel_to_image(fdf, (int) x, (int) y, fdf->color1);
	else
		fdf_put_pixel_to_image(fdf, (int) x, (int) y, fdf->color2);
	return (0);
}


int fdf_put_pixel_to_image(t_fdf *fdf, int x, int y, int color)
{
	unsigned int *dst;


	if (x > fdf->image.w || y > fdf->image.h || x < 0 || y < 0)
	{
		ft_printf("error on x = %d, y = %d\n", x, y);
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
