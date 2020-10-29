/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:20:13 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/29 17:47:48 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			how_many_str(char *arg)
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

static int			how_many_dot(char *arg)
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

static int			**create_map(int h, int w)
{
	int				**res;
	int				i;

	i = 0;
	if (!(res = (int **)malloc(sizeof(int *) * (h + 1))))
		return (NULL);
	while (i < h)
	{
		if (!(res[i] = (int *)malloc(sizeof(int) * w)))
		{
			i--;
			while (i > 0)
			{
				free(res[i]);
				res[i] = NULL;
				i--;
			}
			free(res);
			res = NULL;
			return (NULL);
		}
	}
	
}

void				init_map(t_map *map, char *arg)
{
	map->height = how_many_str(arg);
	map->width = how_many_dot(arg);
	map->map = create_map(map->height, map->width);

	ft_printf("v etom file strok = %i\n", map->height);
	ft_printf("v etom file tochek = %i\n", map->width);
}