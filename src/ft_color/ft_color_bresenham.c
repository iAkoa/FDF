/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_bresenham.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:18:19 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/29 02:10:04 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	ft_color75_100(double z1, double z2, double per, t_win *w)
{
	double	z_min_local;
	double	z_max_local;
	double	z;

	z = z1 + per * (z2 - z1);
	z_min_local = (75.0 / 100.0) * (w->z_max - w->z_min) + w->z_min;
	z_max_local = w->z_max;
	return (ft_colinterpolate(0x00FFFF00, 0x00FF0000,
			(z - z_min_local) / (z_max_local - z_min_local)));
}

static int	ft_color50_75(double z1, double z2, double per, t_win *w)
{
	double	z_min_local;
	double	z_max_local;
	double	z;

	z = z1 + per * (z2 - z1);
	z_min_local = (50.0 / 100.0) * (w->z_max - w->z_min) + w->z_min;
	z_max_local = (75.0 / 100.0) * (w->z_max - w->z_min) + w->z_min ;
	return (ft_colinterpolate(0x0000FF00, 0x00FFFF00,
			(z - z_min_local) / (z_max_local - z_min_local)));
}

static int	ft_color25_50(double z1, double z2, double per, t_win *w)
{
	double	z_min_local;
	double	z_max_local;
	double	z;

	z = z1 + per * (z2 - z1);
	z_min_local = (25.0 / 100) * (w->z_max - w->z_min) + w->z_min;
	z_max_local = (50.0 / 100) * (w->z_max - w->z_min) + w->z_min ;
	return (ft_colinterpolate(0x0000FFFF, 0x0000FF00,
			(z - z_min_local) / (z_max_local - z_min_local)));
}

static int	ft_color0_25(double z1, double z2, double per, t_win *w)
{
	double	z_min_local;
	double	z_max_local;
	double	z;

	z = z1 + per * (z2 - z1);
	z_min_local = 0 + w->z_min;
	z_max_local = (25.0 / 100.0) * (w->z_max - w->z_min) + w->z_min;
	if (w->draw_map_color < 0)
		return (ft_colinterpolate(0, 0x0000FFFFF,
				(z - z_min_local) / (z_max_local - z_min_local)));
	return (ft_colinterpolate(0x000000FF, 0x0000FFFFF,
			(z - z_min_local) / (z_max_local - z_min_local)));
}

int	ft_color_bresenham(double z1, double z2, double per, t_win *w)
{
	double	z;

	z = z1 + per * (z2 - z1);
	if (w->draw_color == -1 || !w->z_no_color)
		return (0x00FFFFFF);
	if (z >= (75.0 / 100.0) * (w->z_max - w->z_min) + w->z_min)
		return (ft_color75_100(z1, z2, per, w));
	else if (z >= (50.0 / 100.0) * (w->z_max - w->z_min) + w->z_min)
		return (ft_color50_75(z1, z2, per, w));
	else if (z >= (25.0 / 100.0) * (w->z_max - w->z_min) + w->z_min)
		return (ft_color25_50(z1, z2, per, w));
	else
		return (ft_color0_25(z1, z2, per, w));
}
