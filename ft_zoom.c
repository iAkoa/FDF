/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:46:57 by pat               #+#    #+#             */
/*   Updated: 2022/02/17 16:39:08 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

t_pixel	*ft_zoom(t_pixel *map, int zoom, t_pixel xy)
{
	t_pixel	*tmp;
	
	xy.x = 0;
	tmp = map;
	while (map->color)
	{
		if (zoom == 1)
		{
			map->x *= 1.3;
			map->y *= 1.3;
			map->z *= 1.3;
		}
		if (zoom == -1)
		{
			map->x /= 1.3;
			map->y /= 1.3;
			map->z /= 1.3;
		}
		map++;
	}
	return (tmp);
}
