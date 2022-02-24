/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:27:29 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/24 18:24:05 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_draw(t_win *w, int x_max, int y_max)
{
	int			i;
	t_vector	v;

	i = 0;
	while (w->map[i].color)
	{
		if (w->map[i + 1].color && (i + 1) % x_max != 0)
		{
			// printf("color vector = %i\n", w->map[i].color);
			v = ft_utils(w->map[i], w->map[i + 1]);
			// printf("color = %i\n", v.p1.color);
			ft_bresenham(v, w, w->ref);
		}
		if (w->map[i + 1].color && i / x_max != y_max - 1)
		{
			v = ft_utils(w->map[i], w->map[i + x_max]);
			ft_bresenham(v, w, w->ref);
		}
		i++;
	}
}
