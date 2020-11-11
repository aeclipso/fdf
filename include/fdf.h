/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:00:30 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/11 10:41:24 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

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
#define ZOOM		2
# define line L

// typedef struct	s_rot
// {
// 	float		x_rot;
// 	float		y_rot;
// 	float		z_rot;
// }				t_rot;


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
	int			color;
	int 		print;
} 				t_point;


typedef struct	s_fdf_image
{
	void	*img;
	char	*addr;
	int		w;
	int		h;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	top;
	float	section;
	float 	line;
}				t_image;


typedef struct	s_fdf_system
{
	int		w;
	int		h;
	void	*mlx;
	void	*window;
	t_image	image;
	t_map	*map;

	int		color1;
	int		color2;
	float	x_r;
	float	y_r;
	float	z_r;
	int		margin_x;
	int		margin_y;

}				t_fdf;



/*
** Functions
*/

void			init_map(t_map *map, char *arg);
void			init_sect(t_fdf *fdf);
void			delete_map(t_map *map);

//Render

int render_manager(t_map *map);
int fdf_put_pixel_to_image(t_fdf *fdf, int x, int y, int color);
int fdf_put_background(t_fdf *fdf, int color);
int fdf_put_line_to_image(t_fdf *fdf, t_point *p1, t_point *p2);
void		draw_line(t_fdf *fdf, int x, int y);
void		create_point(t_fdf *fdf, t_point *point, int x, int y);
void painter(t_fdf *fdf);
//Hooks

int hooks_manager(int keycode, t_fdf *fdf);

// Stop render
int	close_window(t_fdf *fdf);
// Math
float	mod(float nbr);
float	max(float a, float b);
void	x_angle(float x, float *y, float *z, float angle);
void	y_angle(float *x, float y, float *z, float angle);
void	z_angle(float *x, float *y, float z, float angle);
void	proj_hook(int keycode, t_fdf *fdf);
void	*render_menu(t_fdf *fdf);
#endif 

//sega 20-60, 10-70, нужно ограничение с отрицательной стороны тоже
