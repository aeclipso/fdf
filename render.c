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
	fdf->image.line = STEP; //debug it
	ft_printf("[Create Image] X = [%d], Y = [%d], SQR = %d\n", fdf->image.w,
			  fdf->image.h, fdf->image.w * fdf->image.h);
}

void put_matrix_to_image(t_fdf *fdf)
{

}

void painter(t_fdf *fdf)
{
	t_point p1;
	t_point p2;

	p1 = point_init((float)0, (float)0, (float)0);
	p2 = point_init((float)100, (float)100, (float)0);
	init_image(fdf, fdf->w, fdf->h); // Инициализация fdf.image
//	fdf_put_background(fdf, COL_BLACK); // Заполнение цветом)
	fdf_put_line_to_image(fdf, &p1, &p2);
	put_matrix_to_image(fdf);

	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image.img, 20, 20);
}

int render_manager(t_map *map)
{
	t_fdf fdf;

	fdf.map = map;
	init_display(&fdf, "FDF");
	painter(&fdf);
	mlx_key_hook(fdf.window, hooks_manager, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
