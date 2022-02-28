/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:27:29 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/28 13:53:56 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_draw(t_win *w)
{
	int			i;
	t_vector	v;

	i = 0;
	while (w->map[i].color)
	{
		if (w->map[i + 1].color && (i + 1) % w->x_max != 0)
		{
			v = ft_utils(w->map[i], w->map[i + 1]);
			ft_bresenham(v, w, w->ref);
		}
		if (w->map[i + 1].color && i / w->x_max != w->y_max - 1)
		{
			v = ft_utils(w->map[i], w->map[i + w->x_max]);
			ft_bresenham(v, w, w->ref);
		}
		i++;
	}
}
