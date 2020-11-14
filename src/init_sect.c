/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:56:56 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/11 21:27:34 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_sect(t_fdf *fdf)
{
	float	sect_h;
	float	sect_w;

	sect_h = (fdf->image.h * 0.2) / fdf->map->height;
	sect_w = (fdf->image.w * 0.2) / fdf->map->width;
	fdf->image.section = ((int)sect_h < (int)sect_w) ? sect_h : sect_w;
}

int			how_many_str(char *arg)
{
	int		fd;
	int		count;
	char	*s;

	count = 0;
	if (!(fd = open(arg, O_RDONLY)))
		return (0);
	while (get_next_line(fd, &s) > 0)
	{
		free(s);
		count++;
	}
	close(fd);
	return (count);
}

int			how_many_dot(char *arg)
{
	int		fd;
	int		count;
	char	*s;

	count = 0;
	if (!(fd = open(arg, O_RDONLY)))
		return (0);
	if (get_next_line(fd, &s) > 0)
	{
		count = ft_counterwords(s, ' ');
		free(s);
	}
	else
		return (0);
	close(fd);
	return (count);
}
