/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:47:46 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/29 17:20:34 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
◦ open, read, write, close
◦ malloc, free
◦ perror, strerror
◦ exit
◦ All the functions defined in the math library (-lm and man 3 math)
◦ All the functions defined in the miniLibX library.
*/

#include <stdio.h>
#include <errno.h>


void		usage(void)
{
	ft_printf("Need more options\n");
	return ;
}

int				core(char *arg)
{
	t_map		map;

	init_map(&map, arg);
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