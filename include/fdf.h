/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:00:30 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/11 21:02:03 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# define COL_BLACK	0x000000
# define COL_SILVER	0xc0c0c0
# define COL_GRAY	0x808080
# define COL_WHITE	0xffffff
# define COL_MARRON	0x800000
# define COL_RED		0xff0000
# define COL_PURPLE	0x800080
# define COL_FUCHSIA	0xff00ff
# define COL_GREEN	0x008000
# define COL_LIME	0x00ff00
# define COL_OLIVE	0x808000
# define COL_YELLOW	0xffff00
# define W_WIDTH		1920
# define W_HEIGHT	1080
# define STEP		50
# define ZOOM		2

typedef struct		s_map
{
	int				height;
	int				width;
	int				**map;
}					t_map;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_point;

typedef struct		s_fdf_image
{
	void			*img;
	char			*addr;
	int				w;
	int				h;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	float			top;
	float			section;
	float			line;
}					t_image;

typedef struct		s_fdf_system
{
	int				w;
	int				h;
	void			*mlx;
	void			*window;
	t_image			image;
	t_map			*map;
	int				color1;
	int				color2;
	float			x_r;
	float			y_r;
	float			z_r;
	int				margin_x;
	int				margin_y;

}					t_fdf;

typedef struct		s_brazenhem
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				e2;
	int				sx;
	int				sy;
	int				dx;
	int				dy;
	int				err;
}					t_bra;

/*
** Functions
*/
int					how_many_str(char *arg);
int					how_many_dot(char *arg);
void				init_map(t_map *map, char *arg);
void				init_sect(t_fdf *fdf);
void				delete_map(t_map *map);
int					render_manager(t_map *map);
int					fdf_put_pixel_to_image(t_fdf *fdf, int x, int y, int color);
int					fdf_put_background(t_fdf *fdf, int color);
int					fdf_put_line_to_image(t_fdf *fdf, t_point *p1, t_point *p2);
void				draw_line(t_fdf *fdf, int x, int y);
void				create_point(t_fdf *fdf, t_point *point, int x, int y);
void				painter(t_fdf *fdf);
void				init_image(t_fdf *fdf, int width, int height);
void				draw(t_fdf *fdf);
int					hooks_manager(int keycode, t_fdf *fdf);
int					close_window(t_fdf *fdf);
float				mod(float nbr);
float				max(float a, float b);
void				x_angle(float *y, float *z, float angle);
void				y_angle(float *x, float *z, float angle);
void				z_angle(float *x, float *y, float angle);
void				proj_hook(int keycode, t_fdf *fdf);
void				render_menu(t_fdf *fdf);

#endif
