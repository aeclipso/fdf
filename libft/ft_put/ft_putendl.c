/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:57:55 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/28 14:22:51 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putendl(char const *s)
{
	unsigned char	*arr;
	int				i;

	if (!s)
		return ;
	i = 0;
	arr = (unsigned char*)s;
	while (arr[i])
	{
		ft_putchar(arr[i]);
		i++;
	}
	ft_putchar('\n');
}
