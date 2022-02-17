/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:51:48 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/17 18:14:35 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_pixel	*rotation_x(t_pixel *map)
{
	int	i;
	double tmp;

	i = 0;
	while (map[i].color)
	{
		tmp = map[i].y;
		map[i].y = (map[i].y * cos(M_PI / 60)) - (map[i].z * sin(M_PI / 60));
		map[i].z = (tmp * sin(M_PI / 60)) + map[i].z * cos(M_PI / 60);
		i++;
	}
	return (map);
}

t_pixel	*rotation_y(t_pixel *map)
{
	int	i;
	double tmp;

	i = 0;
	while (map[i].color)
	{
		tmp = map[i].x;
		map[i].x = (map[i].x * cos(M_PI / 60)) + (map[i].z * sin(M_PI / 60));
		map[i].z = - (tmp * sin(M_PI / 60)) + (map[i].z * cos(M_PI / 60));
		i++;
	}
	return (map);
}

t_pixel	*rotation_z(t_pixel *map)
{
	int	i;
	double tmp;

	i = 0;
	while (map[i].color)
	{
		tmp = map[i].x;
		map[i].x = (map[i].x * cos(M_PI / 60)) - (map[i].y * sin(M_PI / 60));
		map[i].y = (tmp * sin(M_PI / 60)) + (map[i].y * cos(M_PI / 60));
		i++;
	}
	return (map);
}

t_pixel	*ft_rotation(t_pixel *map, int projection)
{
	if (projection == 1)
		map = rotation_x(map);
	if (projection == 2)
		map = rotation_y(map);
	if (projection == 3)
		map = rotation_z(map);
	return (map);
}

// int main()
// {
// 	int i = 0;
// 	t_pixel *map;
// 	map = ft_parsing("maptest.txt");
// 	while (map[i].color)
// 	{
// 		printf ("x = %f y = %f z = %f\n", map[i].x, map[i].y, map[i].z);
// 		i++;
// 	}
// 	printf("\n\n");
// 	map = ft_rotation(map, 1);
// 	i = 0;
// 	while (map[i].color)
// 	{
// 		printf ("map.x = %f map.y = %f map.z = %f\n", map[i].x, map[i].y, map[i].z);
// 		i++;
// 	}
// 	printf("\n\n");
// 	map = ft_rotation(map, 2);
// 	i = 0;
// 	while (map[i].color)
// 	{
// 		printf ("map.x = %f map.y = %f map.z = %f\n", map[i].x, map[i].y, map[i].z);
// 		i++;
// 	}
// 	printf("\n\n");
// 	map = ft_rotation(map, 3);
// 	i = 0;
// 	while (map[i].color)
// 	{
// 		printf ("map.x = %f map.y = %f map.z = %f\n", map[i].x, map[i].y, map[i].z);
// 		i++;
// 	}
// }