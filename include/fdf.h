/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:00:30 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/09 17:03:36 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

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
#define ZOOM		.2
# define line L
typedef struct	s_map
{
	int			height;
	int			width;
	int			**map;
}				t_map;

typedef struct	s_point
{
	float 		x;
	float 		y;
	float		z;
} 				t_point;


typedef struct	s_fdf_image
{
	void	*img;
	char	*addr;
	int 	w;
	int		h;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float 	line;
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
	float	section;
}				t_fdf;



/*
** Functions
*/

void			init_map(t_map *map, char *arg);
float			init_sect(t_fdf *fdf);

//Render

int render_manager(t_map *map);
int fdf_put_pixel_to_image(t_fdf *fdf, int x, int y, int color);
int fdf_put_background(t_fdf *fdf, int color);
int fdf_put_line_to_image(t_fdf *fdf, t_point *p1, t_point *p2);
void		draw_line(t_fdf *fdf, int x, int y);
void		create_point(t_fdf *fdf, t_point *point, int x, int y);
//Hooks

int hooks_manager(int keycode, t_fdf *fdf);


// Math
float	mod(float nbr);
float	max(float a, float b);
void	x_angle(float x, float *y, float *z, float angle);
void	y_angle(float *x, float y, float *z, float angle);
void	z_angle(float *x, float *y, float z, float angle);

#endif 
