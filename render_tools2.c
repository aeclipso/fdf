/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:23:11 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/10 22:17:33 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		*render_menu(t_fdf *fdf)
{
	char	**menu;
	int		x;
	int		i;

	i = 0;
	x = 12;
	if (!(menu = (char **)malloc(sizeof(char *) * x + 1)))
		return NULL;
	menu[x] = NULL;
	menu[0] = ft_strdup("FDF");
	menu[1] = ft_strdup("WIDTH 1920");
	menu[2] = ft_strdup("HEIGHT 1080");
	menu[3] = ft_strdup("KEYS:");
	menu[4] = ft_strdup("AXIS-X:\tA - Z");
	menu[5] = ft_strdup("AXIS-Y:\tD - C");
	menu[6] = ft_strdup("AXIS-Z:\tF - V");
	menu[7] = ft_strdup("ZOOM:\t\t+ -");
	menu[8] = ft_strdup("PROJECTIONS:\t1 2 3");
	menu[9] = ft_strdup("COLORS:\t< >");
	menu[10] = ft_strdup("Z:\t\t\t[ ]");
	menu[11] = ft_strdup("POSITION: ARROWS-KEYS");
	while (menu[i])
	{
		mlx_string_put(fdf->mlx, fdf->window, 20, 20 * i, COL_LIME, menu[i]);
		// free(menu[i]);
		i++;
	}
	// free(menu);
	
// "FDF\nWIDTH 1920\nHEIGHT 1080\n\tKEYS:\nAXIS-X:\tA - Z\nAXIS-Y:\tD - C\nAXIS-Z:\tF - V\nZOOM:\t\t+ -\nPROJECTIONS:\t1 2 3\nCOLORS:\t< >\nZ:\t\t\t[ ]\nPOSITION: ARROWS-KEYS"
	// int mlx_string_put (void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );

}