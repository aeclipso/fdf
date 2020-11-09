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
		fdf->margin_x = (keycode == 123) ? fdf->margin_x -= 50 : fdf->margin_x;
		fdf->margin_x = (keycode == 124) ? fdf->margin_x += 50 : fdf->margin_x;
		fdf->margin_y = (keycode == 125) ? fdf->margin_y += 50 : fdf->margin_y;
		fdf->margin_y = (keycode == 126) ? fdf->margin_y -= 50 : fdf->margin_y;
	}
	if (keycode == 43 || keycode == 47)
		color_hook(keycode, fdf);
	painter(fdf);
	ft_printf("KeyCode =\t%d\n", keycode);
	return (0);
}

