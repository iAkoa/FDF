/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:39:20 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/01 17:41:16 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_color(t_pixel *map, t_win *w)
{
	int		i;
	double	z_min_local;
	double	z_max_local;

	w->z_max = w->z_min = map->z;
	i = 0;
	while (i < (w->x_max * w->y_max))
	{
		if (map[i].z > w->z_max)
			w->z_max = map[i].z;
		if (map[i].z < w->z_min)
			w->z_min = map[i].z;
		i++;
	}
	// printf("z_max = %f\n", w->z_max);
	// printf("z_max = %f\n", w->z_min);
	i = 0;
	while (i < (w->x_max * w->y_max))
	{
		// printf("map de z = %f\n", map[i].z);
		// printf("map de z red = %f\n", (75.0 / 100.0) * (w->z_max - w->z_min));
		if (map[i].z >= (75.0 / 100.0) * (w->z_max - w->z_min) + w->z_min)
		{
			z_min_local = (75.0 / 100.0) * (w->z_max - w->z_min) + w->z_min;
			z_max_local = w->z_max;
			map[i].color = ft_colinterpolate(0x00FFFF00, 0x00FF0000,
					(map[i].z - z_min_local) / (z_max_local - z_min_local));
		}
		else if (map[i].z >= (50.0 / 100.0) * (w->z_max - w->z_min) + w->z_min)
		{
			z_min_local = (50.0 / 100.0) * (w->z_max - w->z_min) + w->z_min;
			z_max_local = (75.0 / 100.0) * (w->z_max - w->z_min) + w->z_min;
			map[i].color = ft_colinterpolate(0x0000FF00, 0x00FFFF00,
					(map[i].z - z_min_local) / (z_max_local - z_min_local));
		}
		else if (map[i].z >= (25.0 / 100.0) * (w->z_max - w->z_min) + w->z_min)
		{
			z_min_local = (25.0 / 100) * (w->z_max - w->z_min) + w->z_min;
			z_max_local = (50.0 / 100) * (w->z_max - w->z_min) + w->z_min;
			map[i].color = ft_colinterpolate(0x0000FFFF, 0x0000FF00,
					(map[i].z - z_min_local) / (z_max_local - z_min_local));
		}
		else
		{
			z_min_local = 0 + w->z_min;
			z_max_local = (25.0 / 100.0) * (w->z_max - w->z_min) + w->z_min;
			map[i].color = ft_colinterpolate(0x000000FF, 0x0000FFFFF,
					(map[i].z - z_min_local) / (z_max_local - z_min_local));
		}
		map[i].z = map[i].z / w->z_max * w->x_max / 15;
		i++;
	}
}