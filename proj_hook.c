/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:39:42 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/10 20:49:50 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		proj_hook(int keycode, t_fdf *fdf)
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