/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:06:23 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/11/11 16:32:32 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void		create_point(t_fdf *fdf, t_point *point, int x, int y)
{
	point->x = x * fdf->image.section;
	point->y = y * fdf->image.section;
	point->z = fdf->map->map[y][x] / find_qf(fdf) * 2;
	point->color = (point->z) ? 1 : 0;
	point->x -= (fdf->map->width * fdf->image.section) / 2;
	point->y -= (fdf->map->height * fdf->image.section) / 2;
	point->z *= fdf->image.section + fdf->image.top; //?
	x_angle(point->x, &(point->y), &(point->z), fdf->x_r);
	y_angle(&(point->x), point->y, &(point->z), fdf->y_r);
	z_angle(&(point->x), &(point->y), point->z, fdf->z_r);
	point->x += fdf->image.w / 2 + fdf->margin_x;
	point->y += fdf->image.h / 2 + fdf->margin_y;
}

void		draw_line(t_fdf *fdf, int x, int y)
{
	t_point	p1;
	t_point	p2;

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

void		fdf_put_line_to_image_2(t_fdf *fdf, float x, float y, int color)
{
	if (color)
		fdf_put_pixel_to_image(fdf, (int)x, (int)y, fdf->color1);
	else
		fdf_put_pixel_to_image(fdf, (int)x, (int)y, fdf->color2);
}

int			fdf_put_line_to_image(t_fdf *fdf, t_point *p1, t_point *p2)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	m;

	x = p1->x;
	y = p1->y;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	m = max(mod(dx), mod(dy));
	dx /= m;
	dy /= m;
	while ((int)(p2->x - x) || (int)(p2->y - y))
	{
		if (!((int)x > fdf->image.w || x < 0 || (int)y > fdf->image.h || y < 0))
			fdf_put_line_to_image_2(fdf, x, y, p1->color || p2->color);
		x += dx;
		y += dy;
	}
	fdf_put_line_to_image_2(fdf, x, y, p1->color || p2->color);
	return (0);
}

int					fdf_put_pixel_to_image(t_fdf *fdf, int x, int y, int color)
{
	unsigned int	*dst;

	if (x > fdf->image.w || y > fdf->image.h || x < 0 || y < 0)
	{
//		ft_printf("")
		ft_printf("error pixel on x = %d, y = %d, [%d,%d] \n", x, y, fdf->image.w, fdf->image.h);
//		ft_printf("error pixel");
		return 0;
	}
	dst = (unsigned int *)fdf->image.addr;
	dst[x + (y * fdf->image.line_length / 4)] = color;
	return (0);
}

int					fdf_put_background(t_fdf *fdf, int color)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	*dst;

	i = -1;
	size = fdf->image.h * fdf->image.w;
	dst = (unsigned int *)fdf->image.addr;
	ft_printf("Background on %d pixels\n", size);
	while (size > 0 && ++i != size)
		dst[i] = color;
	ft_printf("Background result is %d\n", i);
	return (0);
}
