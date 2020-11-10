/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:56:56 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/10 17:35:18 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		init_sect(t_fdf *fdf)
{
	float	sect_h;
	float	sect_w;

	sect_h = (fdf->image.h - (fdf->image.h / 5)) / (fdf->map->height * 2);
	sect_w = (fdf->image.w - (fdf->image.w / 5)) / (fdf->map->width * 2);

	ft_printf("SECT_H = %3d\nSECT_W = %3d\n", sect_h, sect_w);
	if ((int)sect_h < (int)sect_w)
		return (sect_h);
	else
		return (sect_w);
}

