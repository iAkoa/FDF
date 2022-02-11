/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:51:48 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/10 18:07:10 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_pixel	*rotation_x(t_pixel *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= 15)
	{
		printf("rot.x = %f, rot.y = %f, rot.z = %f\n", map[j].x, map[j].y, map[j].z);
		j++;
	}
	printf("\n\n");
	while (map[i].x)
	{
		map[i].y = (map[i].y * cos(M_PI / 60)) - (map[i].z * sin(M_PI / 60));
		map[i].z = (map[i].y * sin(M_PI / 60) + map[i].z * cos(M_PI / 60));
		i++;
	}
	j = 0;
	while (j <= 15)
	{
		printf(".x = %f, .y = %f, .z = %f\n", map[j].x, map[j].y, map[j].z);
		j++;
	}
	printf("\n\n");
	return (map);
}

t_pixel	*rotation_y(t_pixel *map)
{
	int	i;

	i = 0;
	while (map[i].x)
	{
		map[i].x = (map[i].x * cos(M_PI / 60)) + (map[i].z * sin(M_PI / 60));
		map[i].z = - (map[i].x * sin(M_PI / 60)) + (map[i].z * cos(M_PI / 60));
		i++;
	}
	return (map);
}

t_pixel	*rotation_z(t_pixel *map)
{
	int	i;

	i = 0;
	while (map[i].x)
	{
		map[i].x = (map[i].x * cos(M_PI / 60)) - (map[i].y * sin(M_PI / 60));
		map[i].y = (map[i].x * sin(M_PI / 60)) + (map[i].y * cos(M_PI / 60));
		i++;
	}
	return (map);
}

t_pixel	*ft_rotation(t_pixel *map, int projection)
{
	int	j;

	j = 0;
	if (projection == 1)
		map = rotation_x(map);
	// while (j <= 15)
	// {
	// 	printf("rot.x = %f, rot.y = %f, rot.z = %f\n", map[j].x, map[j].y, map[j].z);
	// 	j++;
	// }
	printf("\n\n");
	if (projection == 2)
		map = rotation_y(map);
	if (projection == 3)
		map = rotation_z(map);
	return (map);
}
