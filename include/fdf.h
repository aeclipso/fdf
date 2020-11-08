/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:00:30 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/08 16:31:54 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "libft.h"
# include "mlx.h"

# define H height;
# define W width;
# define G general;
# define M map;
#define COL_BLACK	0x000000
#define COL_SILVER	0xc0c0c0
#define COL_GRAY	0x808080
#define COL_WHITE	0xffffff
#define COL_MARRON	0x800000
#define COL_RED		0xff0000
#define COL_PURPLE	0x800080
#define COL_FUCHSIA	0xff00ff
#define COL_GREEN	0x008000
#define COL_LIME	0x00ff00
#define COL_OLIVE	0x808000
#define COL_YELLOW	0xffff00

#define W_WIDTH		1920
#define W_HEIGHT	1080
#define STEP		50
# define line L
typedef struct	s_map
{
	int			height;
	int			width;
	int			**map;
}				t_map;

typedef struct	s_fdf_image
{
	void	*img;
	char	*addr;
	int 	w;
	int		h;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		line;
}				t_image;


typedef struct	s_fdf_system
{
	int		w;
	int		h;
	void	*mlx;
	void	*window;
	int		color;
	t_image	image;
	t_map	*map;
}				t_fdf;



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
