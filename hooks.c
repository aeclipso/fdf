#include "fdf.h"

static void color_hook(int keycode, t_fdf *fdf)
{
	static int color;
	color = (keycode == 43) ? color - 1 : color + 1;
	color = (color > 3 || color < 0) ? 0 : color;
	if (color == 0)
	{
		fdf->color1 = COL_RED;
		fdf->color2 = COL_GREEN;
	}
	if (color == 1)
	{
		fdf->color1 = COL_WHITE;
		fdf->color2 = COL_YELLOW;
	}
	if (color == 2)
	{
		fdf->color1 = COL_PURPLE;
		fdf->color2 = COL_YELLOW;
	}
	if (color == 3)
	{
		fdf->color1 = COL_SILVER;
		fdf->color2 = COL_PURPLE;
	}
}

int hooks_manager(int keycode, t_fdf *fdf)
{
	if (keycode == 53 || keycode == 256 || keycode == 259)
	{
		mlx_destroy_window(fdf->mlx, fdf->window);
		exit(0);
	}
	if (keycode > 122 && keycode < 127)
	{
		fdf->margin_x = (keycode == 123) ? fdf->margin_x -= 10 : fdf->margin_x;
		fdf->margin_x = (keycode == 124) ? fdf->margin_x += 10 : fdf->margin_x;
		fdf->margin_y = (keycode == 125) ? fdf->margin_y += 10 : fdf->margin_y;
		fdf->margin_y = (keycode == 126) ? fdf->margin_y -= 10 : fdf->margin_y;
	}
	if (keycode >= 0 && keycode <= 2)
	{
		fdf->x_r = (keycode == 0) ? fdf->x_r -= 0.01 : fdf->x_r;
		fdf->y_r = (keycode == 1) ? fdf->y_r -= 0.01 : fdf->y_r;
		fdf->z_r = (keycode == 2) ? fdf->z_r -= 0.01 : fdf->z_r;
	}
	if (keycode >= 6 && keycode <= 8)
	{
		fdf->x_r = (keycode == 6) ? fdf->x_r += 0.01 : fdf->x_r;
		fdf->y_r = (keycode == 7) ? fdf->y_r += 0.01 : fdf->y_r;
		fdf->z_r = (keycode == 8) ? fdf->z_r += 0.01 : fdf->z_r;
	}
	if (keycode == 69 || keycode == 78)
	{	//ломается при выходе за границы экрана
		fdf->image.w = (keycode == 69) ? fdf->image.w += 1 : fdf->image.w;
		fdf->image.h = (keycode == 69) ? fdf->image.h += 1 : fdf->image.h;
		fdf->image.w = (keycode == 78) ? fdf->image.w -= 1 : fdf->image.w;
		fdf->image.h = (keycode == 78) ? fdf->image.h -= 1 : fdf->image.h;
	}

	if (keycode == 43 || keycode == 47)
		color_hook(keycode, fdf);
	painter(fdf);
	ft_printf("KeyCode =\t%d\n", keycode);
	return (0);
}

