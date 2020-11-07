/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:20:13 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/07 17:17:37 by aeclipso         ###   ########.fr       */
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

static void			*deleter(size_t i, int **res)
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

static int			**create_mem_map(int h, int w)
{
	int				**res;
	int				i;

	i = 0;
	if (!(res = (int **)malloc(sizeof(int *) * (h + 1))))
		return (NULL);
	while (i < h)
	{
		if (!(res[i] = (int *)malloc(sizeof(int) * w)))
			return(deleter(i, res));
		i++;
	}
	res[i] = NULL;
	return (res);
}

void				fill_str(t_map *map, char *s, int counter)
{
	char			**spl;
	int				i;

	i = 0;
	spl = ft_strsplit(s, ' ');
	while (i < map->width)
	{
		map->map[counter][i] = ft_atoi(spl[i]);
		i++;
	}
}

int					readfrom(t_map *map, char *arg)
{
	int				fd;
	char			*s;
	int				counter;

	counter = 0;
	if (!(fd = open(arg, O_RDONLY)))
		return (0);
	while (get_next_line(fd, &s) > 0 && counter < map->height)
	{
		if ((int)ft_counterwords(s, ' ') != map->width)
			return (0);
		fill_str(map, s, counter);
		free(s);
		counter++;
	}
	close(fd);
	return (1);
}

void				init_map(t_map *map, char *arg)
{
	map->height = how_many_str(arg);
	map->width = how_many_dot(arg);
	map->map = create_mem_map(map->height, map->width);
	if (readfrom(map, arg) == 0)
	{
		ft_printf("Wrong Mapfile\n");
	}
	ft_printf("v etom file strok = %i\n", map->height);
	ft_printf("v etom file tochek = %i\n", map->width);


	int i = -1;
	int j = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			ft_printf("%3d", map->map[i][j]);
		}
		ft_printf("\n");
	}
}