/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:33:46 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/11 17:38:09 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				escape_map(t_map *map)
{

	int				i;
	int				j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] < -1000)
				map->map[i][j] = -1000;
			if (map->map[i][j] > 1000)
				map->map[i][j] = 1000;
		}
	}
}
