/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:46:57 by pat               #+#    #+#             */
/*   Updated: 2022/02/07 08:46:14 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_pixel *ft_zoom(t_pixel *map, int zoom)
{
	t_pixel *tmp;
	
	tmp = map;
	while (map->color)
	{
		if (zoom = 1)
		{
			map->x *= 2;
			map->y *= 2;
			map->z *= 2;  
		}
		if (zoom = -1)
		{
			map->x /= 2;
			map->y /= 2;
			map->z /= 2;  
		}
		map++;
	}
	return(tmp);
}