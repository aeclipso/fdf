/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:09:19 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/11/11 21:27:44 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			init_display(t_fdf *fdf, char *title)
{
	fdf->w = W_WIDTH;
	fdf->h = W_HEIGHT;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, fdf->w, fdf->h, title);
	fdf->color1 = COL_RED;
	fdf->color2 = COL_GREEN;
	fdf->x_r = -3.834442f;
	fdf->y_r = -2.534443f;
	fdf->z_r = -2.614443f;
	fdf->margin_x = 0;
	fdf->margin_y = 0;
	fdf->image.w = fdf->w;
	fdf->image.h = fdf->h;
	fdf->image.top = 0.2f;
	init_sect(fdf);
}

void			init_image(t_fdf *fdf, int width, int height)
{
	fdf->image.img = mlx_new_image(fdf->mlx, width + 1, height + 1);
	fdf->image.addr = mlx_get_data_addr(fdf->image.img,
										&fdf->image.bits_per_pixel,
										&fdf->image.line_length,
										&fdf->image.endian);
}

void			draw(t_fdf *fdf)
{
	int x;
	int y;

	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
			draw_line(fdf, x, y);
	}
}

int				close_window(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->image.img);
	mlx_destroy_window(fdf->mlx, fdf->window);
	exit(0);
}

int				render_manager(t_map *map)
{
	t_fdf fdf;

	fdf.map = map;
	init_display(&fdf, "FDF");
	painter(&fdf);
	mlx_hook(fdf.window, 2, 0, hooks_manager, &fdf);
	mlx_hook(fdf.window, 17, 1, close_window, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
