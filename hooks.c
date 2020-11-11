/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:51:26 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/11/11 10:55:20 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void			proj_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 18)
	{
		fdf->x_r = -3.834442f;
		fdf->y_r = -2.534443f;
		fdf->z_r = -2.614443f;
	}
	if (keycode == 19)
	{
		fdf->x_r = 0.0f;
		fdf->y_r = 0.0f;
		fdf->z_r = 0.0f;
	}
	if (keycode == 20)
	{
		fdf->x_r = 2.0f;
		fdf->y_r = 1.0f;
		fdf->z_r = 3.0f;
	}
}

static void		color_hook(int keycode, t_fdf *fdf)
{
	static int	color;

	color = (keycode == 43) ? color - 1 : color + 1;
	color = (color > 3) ? 0 : color;
	color = (color < 0) ? 3 : color;
	if (color == 0)
	{
		fdf->color1 = COL_RED;
		fdf->color2 = COL_GREEN;
	}
	else if (color == 1)
	{
		fdf->color1 = COL_WHITE;
		fdf->color2 = COL_YELLOW;
	}
	else if (color == 2)
	{
		fdf->color1 = COL_PURPLE;
		fdf->color2 = COL_YELLOW;
	}
	else if (color == 3)
	{
		fdf->color1 = COL_SILVER;
		fdf->color2 = COL_PURPLE;
	}
}

//static void		change_size(int keycode, t_fdf *fdf)
//{
//	if (keycode == 27 && fdf->image.w > 51 && fdf->image.h > 51)
//	{
//		fdf->image.w *= 0.95;
//		fdf->image.h *= 0.95;
//	}
//	else if (keycode == 27)
//	{
//		fdf->image.w = fdf->w / 32;
//		fdf->image.h = fdf->h / 32;
//	}
//	else if (keycode == 24 && (fdf->image.w * fdf->image.h < 132710400))
//	{
//		fdf->image.w *= 1.05;
//		fdf->image.h *= 1.05;
//	}
//	ft_printf("Inscrease to x = %d y = %d\n", fdf->image.w, fdf->image.h);
//}

static void		change_size(int keycode, t_fdf *fdf)
{
	if (keycode == 27)
	{
		fdf->image.section--;
	}
	else if (keycode == 24)
	{
		fdf->image.section++;
	}
	ft_printf("[Change_size] fdf->image.section = %f\n", fdf->image.section);
}

//static void		change_top(int keycode, t_fdf *fdf)
//{
//	if (keycode == 30 && fdf->image.top < 2.0f) //смотреть во что превращается z при этом тоже
//		fdf->image.top += 0.2f;
//	else if (keycode == 33 && fdf->image.top > -2.1f)
//		fdf->image.top -= 0.2f;
//}

static void		change_top(int keycode, t_fdf *fdf)
{
	if (keycode == 30) //смотреть во что превращается z при этом тоже
		fdf->image.top += 0.5f;
	else if (keycode == 33)
		fdf->image.top -= 0.5f;
}

int				hooks_manager(int keycode, t_fdf *fdf)
{
	ft_printf("keycode = %d\n", keycode);
	if (keycode == 53 || keycode == 256 || keycode == 259)
		close_window(fdf);
	fdf->margin_x = (keycode == 123) ? fdf->margin_x -= 10 : fdf->margin_x;
	fdf->margin_x = (keycode == 124) ? fdf->margin_x += 10 : fdf->margin_x;
	fdf->margin_y = (keycode == 125) ? fdf->margin_y += 10 : fdf->margin_y;
	fdf->margin_y = (keycode == 126) ? fdf->margin_y -= 10 : fdf->margin_y;
	fdf->x_r = (keycode == 0) ? fdf->x_r -= 0.05 : fdf->x_r;
	fdf->y_r = (keycode == 1) ? fdf->y_r -= 0.05 : fdf->y_r;
	fdf->z_r = (keycode == 2) ? fdf->z_r -= 0.05 : fdf->z_r;
	fdf->x_r = (keycode == 6) ? fdf->x_r += 0.05 : fdf->x_r;
	fdf->y_r = (keycode == 7) ? fdf->y_r += 0.05 : fdf->y_r;
	fdf->z_r = (keycode == 8) ? fdf->z_r += 0.05 : fdf->z_r;
	if (keycode == 24 || keycode == 27)
		change_size(keycode, fdf);
	if (keycode == 43 || keycode == 47)
		color_hook(keycode, fdf);
	if (keycode == 33 || keycode == 30)
		change_top(keycode, fdf);
	if (keycode >= 18 && keycode <= 20)
		proj_hook(keycode, fdf);
	painter(fdf);
	return (0);
}
