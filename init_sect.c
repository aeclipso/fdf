/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:56:56 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/10 22:12:02 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void		init_sect(t_fdf *fdf)
{
	float	sect_h;
	float	sect_w;

	sect_h = (fdf->image.h * 0.2) / fdf->map->height;
	sect_w = (fdf->image.w * 0.2) / fdf->map->width;
	fdf->image.section = ((int)sect_h < (int)sect_w) ? sect_h : sect_w;
}
