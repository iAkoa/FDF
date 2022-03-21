/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:46:57 by pat               #+#    #+#             */
/*   Updated: 2022/03/19 03:12:01 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_pixel	*ft_zoom(t_pixel *map, int zoom, t_pixel xy)
{
	t_pixel	*tmp;

	xy.x = 0;
	tmp = map;
	while (map->color)
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
		map++;
	}
	return (tmp);
}
