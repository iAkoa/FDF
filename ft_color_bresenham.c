/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_bresenham.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:18:19 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/28 19:57:06 by rmattheo         ###   ########lyon.fr   */
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
	// printf("z_max = %f\n", w->z_max);
	// printf("z_min = %f\n", w->z_min);
	// printf("per = %f\n", per);
	z = z1 + per * (z2 - z1);
	// printf("z1 = %f\n", z);
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
		return (ft_colinterpolate(0x000000FF, 0x0000FFFFF,
				(z - z_min_local) / (z_max_local - z_min_local)));
		}
		i++;
}
