/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:23:11 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/11 21:27:42 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				render_menu2(char **menu, int len)
{
	menu[len] = NULL;
	menu[0] = ft_strdup("FDF");
	menu[1] = ft_strdup("WIDTH 1920");
	menu[2] = ft_strdup("HEIGHT 1080");
	menu[3] = ft_strdup("KEYS:");
	menu[4] = ft_strdup("AXIS-X:\tA - Z");
	menu[5] = ft_strdup("AXIS-Z:\tS - X");
	menu[6] = ft_strdup("AXIS-Y:\tD - C");
	menu[7] = ft_strdup("ZOOM:\t\t+ -");
	menu[8] = ft_strdup("PROJECTIONS:\t1 2 3");
	menu[9] = ft_strdup("COLORS:\t< >");
	menu[10] = ft_strdup("Z:\t\t\t[ ]");
	menu[11] = ft_strdup("POSITION: ARROWS-KEYS");
}

void				render_menu(t_fdf *fdf)
{
	char			**menu;
	int				i;
	int				x;

	x = 12;
	i = -1;
	if (!(menu = (char **)malloc(sizeof(char *) * x + 1)))
		return ;
	render_menu2(menu, x);
	while (menu[++i])
	{
		mlx_string_put(fdf->mlx, fdf->window, 20, 20 * i, COL_LIME, menu[i]);
		free(menu[i]);
	}
	free(menu);
}

int					fdf_put_background(t_fdf *fdf, int color)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	*dst;

	i = -1;
	size = fdf->image.h * fdf->image.w;
	dst = (unsigned int *)fdf->image.addr;
	while (size > 0 && ++i != size)
		dst[i] = color;
	return (0);
}

void				create_point(t_fdf *fdf, t_point *point, int x, int y)
{
	point->x = x * fdf->image.section;
	point->y = y * fdf->image.section;
	point->z = fdf->map->map[y][x];
	point->color = (point->z) ? 1 : 0;
	point->x -= (fdf->map->width * fdf->image.section) / 2;
	point->y -= (fdf->map->height * fdf->image.section) / 2;
	point->z *= fdf->image.section * fdf->image.top;
	x_angle(&(point->y), &(point->z), fdf->x_r);
	y_angle(&(point->x), &(point->z), fdf->y_r);
	z_angle(&(point->x), &(point->y), fdf->z_r);
	point->x += fdf->image.w / 2 + fdf->margin_x;
	point->y += fdf->image.h / 2 + fdf->margin_y;
}

void				painter(t_fdf *fdf)
{
	static int	created;

	if (created == 0)
		created = 1;
	else
	{
		mlx_destroy_image(fdf->mlx, fdf->image.img);
		mlx_clear_window(fdf->mlx, fdf->window);
	}
	init_image(fdf, fdf->image.w, fdf->image.h);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image.img, 0, 0);
	render_menu(fdf);
}
