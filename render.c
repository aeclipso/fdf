#include "include/fdf.h"

void init_display(t_fdf *fdf, char *title)
{
	fdf->w = W_WIDTH;
	fdf->h = W_HEIGHT;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, fdf->w, fdf->h, title);
	fdf->color = COL_YELLOW;
}


void init_image(t_fdf *fdf, int width, int height)
{
	fdf->image.img = mlx_new_image(fdf->mlx, width, height);
	fdf->image.addr = mlx_get_data_addr(fdf->image.img,
										&fdf->image.bits_per_pixel,
										&fdf->image.line_length,
										&fdf->image.endian);
	fdf->image.w = width;
	fdf->image.h = height;
	fdf->color = COL_RED;
	ft_printf("[Create Image] X = [%d], Y = [%d], SQR = %d\n", fdf->image.w,
			  fdf->image.h, fdf->image.w * fdf->image.h);
}


int render_manager(t_map *map)
{
	t_fdf fdf;

	init_display(&fdf, "FDF");


	init_image(&fdf, fdf.w, fdf.h); // Инициализация fdf.image
	fdf_put_background(&fdf, COL_LIME); // Заполнение цветом
//	fdf_put_pixel_to_image(&fdf, 1919, 1078, COL_WHITE); // Напечатать пиксель
	fdf_put_line_to_image(&fdf, 0, 0, fdf.w - 1 ,fdf.h - 1); //напечатать линию
	mlx_put_image_to_window(fdf.mlx, fdf.window, fdf.image.img, 0, 0);
	mlx_key_hook(fdf.window, hooks_manager, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
