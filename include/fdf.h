/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:00:30 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/07 17:12:27 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "libft.h"
# include "fdf2.h"
# include "mlx.h"

# define H height;
# define W width;
# define G general;
# define M map;

typedef struct	s_map
{
	int		height;
	int		width;
	int			**map;
}				t_map;


/*
** Functions
*/

void			init_map(t_map *map, char *arg);

//Render

int render_manager(t_map *map);
int	fdf_put_pixel_to_image(t_fdf *fdf, int x, int y, int color);
int fdf_put_background(t_fdf *fdf, int color);
int fdf_put_line_to_image(t_fdf *fdf, int x1, int y1, int x2, int y2);

//Hooks

int hooks_manager(int keycode, t_fdf *fdf);


#endif 
