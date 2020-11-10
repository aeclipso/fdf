/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:47:46 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/10 22:10:25 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include <stdio.h>
#include <errno.h>

void		usage(void)
{
	ft_printf("Need more options\n");
	return ;
}

void			delete_map(t_map *map)
{
	int			i;
	int			**del;

	i = 0;
	del = map->map;
	while (i < map->height)
	{
		free(del[i]);
		del[0] = NULL;
		i++;
	}
	free(del);
	del = NULL;
}

int				core(char *arg)
{
	t_map		map;

	init_map(&map, arg);
	render_manager(&map);
	delete_map(&map);
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 2 && argv)
		usage();
	else
		core(argv[1]);
	return (0);
}
