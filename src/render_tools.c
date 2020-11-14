/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:06:23 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/11/11 21:27:40 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				draw_line(t_fdf *fdf, int x, int y)
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

void				fdf_put_line_to_image_2(t_fdf *fdf,
float x, float y, int color)
{
	if (color)
		fdf_put_pixel_to_image(fdf, (int)x, (int)y, fdf->color1);
	else
		fdf_put_pixel_to_image(fdf, (int)x, (int)y, fdf->color2);
}

void				fdf_bra(t_bra *bra, t_point *p1, t_point *p2)
{
	bra->x0 = (int)p1->x;
	bra->y0 = (int)p1->y;
	bra->x1 = (int)p2->x;
	bra->y1 = (int)p2->y;
	bra->dx = ft_abs(bra->x1 - bra->x0);
	bra->dy = ft_abs(bra->y1 - bra->y0);
	bra->sx = (bra->x0 < bra->x1) ? 1 : -1;
	bra->sy = (bra->y0 < bra->y1) ? 1 : -1;
	bra->err = bra->dx - bra->dy;
}

int					fdf_put_line_to_image(t_fdf *fdf, t_point *p1, t_point *p2)
{
	t_bra			bra;

	fdf_bra(&bra, p1, p2);
	while (1)
	{
		fdf_put_line_to_image_2(fdf, bra.x0, bra.y0, p1->color || p2->color);
		if (bra.x0 == bra.x1 && bra.y0 == bra.y1)
			return (0);
		bra.e2 = (bra.err << 1);
		if (bra.e2 > -bra.dy)
		{
			bra.err -= bra.dy;
			bra.x0 += bra.sx;
		}
		if (bra.e2 < bra.dx)
		{
			bra.err += bra.dx;
			bra.y0 += bra.sy;
		}
	}
}

int					fdf_put_pixel_to_image(t_fdf *fdf, int x, int y, int color)
{
	unsigned int	*dst;

	if (x > fdf->image.w || y > fdf->image.h || x < 0 || y < 0)
	{
		return (0);
	}
	dst = (unsigned int *)fdf->image.addr;
	dst[x + (y * fdf->image.line_length / 4)] = color;
	return (0);
}
