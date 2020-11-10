#include "include/fdf.h"

void init_display(t_fdf *fdf, char *title)
{
	fdf->w = W_WIDTH;
	fdf->h = W_HEIGHT;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, fdf->w, fdf->h, title);
	fdf->color1 = COL_RED;
	fdf->color2 = COL_GREEN;
	fdf->background_color = COL_BLACK;
	fdf->x_r = -3.834442f;
	fdf->y_r = -2.534443f;
	fdf->z_r = -2.614443f;
	fdf->margin_x = 0;
	fdf->margin_y = 0;
	fdf->image.w = fdf->w;
	fdf->image.h = fdf->h;
}


void init_image(t_fdf *fdf, int width, int height)
{
	fdf->image.img = mlx_new_image(fdf->mlx, width + 1, height + 1);
	fdf->image.addr = mlx_get_data_addr(fdf->image.img,
										&fdf->image.bits_per_pixel,
										&fdf->image.line_length,
										&fdf->image.endian);
//	fdf->image.w = width;
//	fdf->image.h = height;
<<<<<<< HEAD
	// fdf->image.w = width / 2;
	// fdf->image.h = height / 2;
	fdf->margin_x = width / 8;
	fdf->margin_y = height / 8;
=======
>>>>>>> 2f322e6cea811b0f27ba98c2611733c1dad20e3c
	fdf->image.line = STEP; //debug it
	init_sect(fdf);
	ft_printf("[Create Image] X = [%d], Y = [%d], SQR = %d, SECTION %f\n",
			  fdf->image.w,
			  fdf->image.h, fdf->image.w * fdf->image.h, fdf->image.section);

}

void draw(t_fdf *fdf)
{
	int x;
	int y;

	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
			draw_line(fdf, x, y);
	}
}

void painter(t_fdf *fdf)
{
	static int created;
	if (created == 0)
		created = 1;
	else
	{
		mlx_destroy_image(fdf->mlx, fdf->image.img);
		mlx_clear_window(fdf->mlx, fdf->window);
	}
	init_image(fdf, fdf->image.w, fdf->image.h);// Инициализация fdf.image

//	fdf_put_background(fdf, COL_WHITE);
	draw(fdf);
	ft_printf("--->Margin x = %d y = %d\n", fdf->margin_x, fdf->margin_y);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image.img,
							((fdf->w - fdf->image.w) / 2) + fdf->margin_x, ((fdf->h - fdf->image.h) / 2) + fdf->margin_y) ;
}

int close_window(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->image.img);
	mlx_destroy_window(fdf->mlx, fdf->window);
	exit(0);
}


int render_manager(t_map *map)
{
	t_fdf fdf;

	fdf.map = map;
	init_display(&fdf, "FDF");
	painter(&fdf);
	mlx_hook(fdf.window, 2, 0, hooks_manager, &fdf);
//	mlx_key_hook(fdf.window, hooks_manager, &fdf);
	mlx_hook(fdf.window, 17, 1, close_window, &fdf);

	mlx_loop(fdf.mlx);
	return (0);
}
