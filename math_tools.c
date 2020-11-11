/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:54:15 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/11/10 21:54:24 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

float	max(float a, float b)
{
	return (a > b ? a : b);
}

float	mod(float i)
{
	return (i < 0 ? -i : i);
}

void	x_angle(float x, float *y, float *z, float angle)
{
	float y2;
	float z2;

//	ft_printf("y = %f, z = %f, angle = %f\n", *y,*z,angle);
	y2 = *y;
	z2 = *z;
	*y = y2 * cos(angle) + z2 * sin(angle);
	*z = -y2 * sin(angle) + z2 * cos(angle);
//	*y += 0.2f;
//	*z += 0.2f;
}

void	y_angle(float *x, float y, float *z, float angle)
{
	float x2;
	float z2;

	x2 = *x;
	z2 = *z;
	*x = x2 * cos(angle) + z2 * sin(angle);
	*z = -x2 * sin(angle) + z2 * cos(angle);
}

void	z_angle(float *x, float *y, float z, float angle)
{
	float y2;
	float x2;

	y2 = *y;
	x2 = *x;
	*x = x2 * cos(angle) - y2 * sin(angle);
	*y = x2 * sin(angle) + y2 * cos(angle);
}
