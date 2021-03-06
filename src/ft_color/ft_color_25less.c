/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_25less.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 03:31:30 by pat               #+#    #+#             */
/*   Updated: 2022/05/27 14:09:12 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_full_white(t_pixel *map, t_win *w)
{
	int	i;

	i = 0;
	while (i < (w->x_max * w->y_max))
	{
		map[i].color = 0x00FFFFF;
		i++;
	}
}

void	ft_color_25less(t_pixel *map, t_win *w)
{
	w->z_max = w->z_min;
	w->z_min = map->z;
	w->i = 0;
	while (w->i < (w->x_max * w->y_max))
	{
		if (map[w->i].z > w->z_max)
			w->z_max = map[w->i].z;
		if (map[w->i].z < w->z_min)
			w->z_min = map[w->i].z;
		w->i++;
	}
}
