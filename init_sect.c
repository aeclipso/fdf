/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:56:56 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/09 17:02:31 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		init_sect(t_fdf *fdf)
{
	float	sect_h;
	float	sect_w;

	sect_h = 864 / (fdf->map->height * 2);
	sect_w = 1536 / (fdf->map->width * 2);

	if ((int)sect_h < (int)sect_w)
		return (sect_h);
	else
		return (sect_w);
}

