//
// Created by Kudzu Psylocke on 11/7/20.
//


#ifndef SHARE_FDF_FDF2_H
#define SHARE_FDF_FDF2_H

#include "fdf.h"

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

typedef struct	s_fdf_image
{
	void	*img;
	char	*addr;
	int 	w;
	int		h;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} 				t_image;


typedef struct	s_fdf_system
{
	int		w;
	int		h;
	void	*mlx;
	void	*window;
	int		color;
	t_image image;
}				t_fdf;



#endif //SHARE_FDF_FDF2_H
