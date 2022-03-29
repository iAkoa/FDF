/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:39:20 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/28 23:50:13 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	ft_color75_100(t_pixel *map, t_win *w)
{
	double	z_min_local;
	double	z_max_local;

	z_min_local = (75.0 / 100.0) * (w->z_max - w->z_min) + w->z_min;
	z_max_local = w->z_max;
	map[w->i].color = ft_colinterpolate(0x00FFFF00, 0x00FF0000,
			(map[w->i].z - z_min_local) / (z_max_local - z_min_local));
}

static void	ft_color50_75(t_pixel *map, t_win *w)
{
	double	z_min_local;
	double	z_max_local;

	z_min_local = (50.0 / 100.0) * (w->z_max - w->z_min) + w->z_min;
	z_max_local = (75.0 / 100.0) * (w->z_max - w->z_min) + w->z_min;
	map[w->i].color = ft_colinterpolate(0x0000FF00, 0x00FFFF00,
			(map[w->i].z - z_min_local) / (z_max_local - z_min_local));
}

static void	ft_color25_50(t_pixel *map, t_win *w)
{
	double	z_min_local;
	double	z_max_local;

	z_min_local = (25.0 / 100) * (w->z_max - w->z_min) + w->z_min;
	z_max_local = (50.0 / 100) * (w->z_max - w->z_min) + w->z_min;
	map[w->i].color = ft_colinterpolate(0x0000FFFF, 0x0000FF00,
			(map[w->i].z - z_min_local) / (z_max_local - z_min_local));
}

static void	ft_color0_25(t_pixel *map, t_win *w)
{
	double	z_min_local;
	double	z_max_local;

	z_min_local = 0 + w->z_min;
	z_max_local = (25.0 / 100.0) * (w->z_max - w->z_min) + w->z_min;
	map[w->i].color = ft_colinterpolate(0x000000FF, 0x0000FFFFF,
			(map[w->i].z - z_min_local) / (z_max_local - z_min_local));
}

void	ft_color(t_pixel *map, t_win *w)
{
	ft_color_25less(map, w);
	w->i = 0;
	while (w->i < (w->x_max * w->y_max))
	{
		if (map[w->i].z >= (75.0 / 100.0)
			* (w->z_max - w->z_min) + w->z_min)
			ft_color75_100(map, w);
		else if (map[w->i].z >= (50.0 / 100.0)
			* (w->z_max - w->z_min) + w->z_min)
			ft_color50_75(map, w);
		else if (map[w->i].z >= (25.0 / 100.0)
			* (w->z_max - w->z_min) + w->z_min)
			ft_color25_50(map, w);
		else
			ft_color0_25(map, w);
		map[w->i].z = map[w->i].z / w->z_max * w->x_max / 15;
		w->i++;
	}
}
