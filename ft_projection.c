/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:06:57 by pat               #+#    #+#             */
/*   Updated: 2022/02/10 17:12:28 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	*ft_projection(t_pixel *map)
{
	int		i;
	double	x_temp;
	double	y_temp;
	t_pixel	*map2d;

	i = 0;
	while (map[i].x)
	{
		x_temp = map[i].x;
		y_temp = map[i].y;
		map[i].x = (sqrt(2) / 2) * (x_temp - y_temp);
		map[i].y = (sqrt(2) / 2) * map[i].z
				- ((1 / sqrt(6)) * (x_temp - y_temp));
	}
	return (map);
}
