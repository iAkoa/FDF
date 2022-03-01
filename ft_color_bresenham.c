/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_bresenham.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:18:19 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/01 03:56:23 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_color_bresenham(double z1, double z2, double per, t_win *w)
{
	int		i;
	double	z_min_local;
	double	z_max_local;
	double	z;

	i = 0;
	z = z1 + per * (z2 - z1);
	if (w->draw_color == -1)
		return(0x00FFFFFF);
	if (z >= (75.0 / 100) * (w->z_max - w->z_min))
	{
		z_min_local = (75.0 / 100) * (w->z_max - w->z_min);
		z_max_local = w->z_max;
		return (ft_colinterpolate(0x00FFFF00, 0x00FF0000,
				(z - z_min_local) / (z_max_local - z_min_local)));
	}
	else if (z >= (50.0 / 100) * (w->z_max - w->z_min))
	{
		z_min_local = (50.0 / 100) * (w->z_max - w->z_min);
		z_max_local = (75.0 / 100) * w->z_max;
		return (ft_colinterpolate(0x0000FF00, 0x00FFFF00,
				(z - z_min_local) / (z_max_local - z_min_local)));
	}
	else if (z >= (25.0 / 100) * (w->z_max - w->z_min))
	{
		z_min_local = (25.0 / 100) * (w->z_max - w->z_min);
		z_max_local = (50.0 / 100) * w->z_max;
		return (ft_colinterpolate(0x0000FFFF, 0x0000FF00,
				(z - z_min_local) / (z_max_local - z_min_local)));
	}
	else
	{
		z_min_local = 0;
		z_max_local = (25.0 / 100) * w->z_max;
		if(w->draw_map_color < 0)
			return (ft_colinterpolate(0, 0x0000FFFFF,
				(z - z_min_local) / (z_max_local - z_min_local)));
		return (ft_colinterpolate(0x000000FF, 0x0000FFFFF,
				(z - z_min_local) / (z_max_local - z_min_local)));
	}
	i++;
}
