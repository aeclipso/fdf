#include "fdf.h"

int hooks_manager(int keycode, t_fdf *fdf)
{
	if (keycode == 53 || keycode == 256 || keycode == 259)
	{
		mlx_destroy_window(fdf->mlx, fdf->window);
		exit(0);
	}
	ft_printf("KeyCode =\t%d\n", keycode);
	return (0);
}
