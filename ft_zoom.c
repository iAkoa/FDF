/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:46:57 by pat               #+#    #+#             */
/*   Updated: 2022/02/10 18:03:38 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

t_pixel	*ft_zoom(t_pixel *map, int zoom)
{
	t_pixel	*tmp;

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

int	main(int argc, char **argv)
{
	t_pixel	*map;
	int		i;
	int		j;

	i = 0;
	map = ft_parsing(argv[1]);
	while (i < 5)
	{
		map = ft_rotation(map, 1);
		j = 0;
		// // while (j <= 15)
		// // {
		// // 	printf("map.x = %f, map.y = %f, map.z = %f\n", map[j].x, map[j].y, map[j].z);
		// // 	j++;
		// }
		printf("\n\n");
		i++;
	}
}
