/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:46:57 by pat               #+#    #+#             */
/*   Updated: 2022/05/27 14:03:33 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_pixel	*ft_zoom(t_pixel *map, int zoom, t_win *w)
{
	t_pixel	*tmp;
	int		i;

	i = 0;
	tmp = map;
	while (i < (w->x_max * w->y_max))
	{
		if (zoom == 1)
		{
			map->x *= 1.2;
			map->y *= 1.2;
			map->z *= 1.2;
		}
		if (zoom == -1)
		{
			map->x /= 1.2;
			map->y /= 1.2;
			map->z /= 1.2;
		}
		i++;
		map++;
	}
	return (tmp);
}
