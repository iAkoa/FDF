/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:46:57 by pat               #+#    #+#             */
/*   Updated: 2022/03/29 01:57:08 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_pixel	*ft_zoom(t_pixel *map, int zoom, t_win *w)
{
	t_pixel	*tmp;
	int	i;

	i = 0;
	tmp = map;
	// printf("w->x_max * w->y_max = %i\n", w->x_max * w->y_max);
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
