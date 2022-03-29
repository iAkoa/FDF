/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:51:48 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/29 00:20:14 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_pixel	*rotation_x(t_pixel *map, int s)
{
	int		i;
	double	tmp;

	i = 0;
	while (map[i].color && s == 1)
	{
		tmp = map[i].y;
		map[i].y = (map[i].y * cos(M_PI / 60)) - (map[i].z * sin(M_PI / 60));
		map[i].z = (tmp * sin(M_PI / 60)) + map[i].z * cos(M_PI / 60);
		i++;
	}
	while (map[i].color && s == -1)
	{
		tmp = map[i].y;
		map[i].y = (map[i].y * cos(-M_PI / 60))
			- (map[i].z * sin(-M_PI / 60));
		map[i].z = (tmp * sin(-M_PI / 60))
			+ map[i].z * cos(-M_PI / 60);
		i++;
	}
	return (map);
}

t_pixel	*rotation_y(t_pixel *map, int s)
{
	int		i;
	double	tmp;

	i = 0;
	while (map[i].color && s == 2)
	{
		tmp = map[i].x;
		map[i].x = (map[i].x * cos(M_PI / 60)) + (map[i].z * sin(M_PI / 60));
		map[i].z = - (tmp * sin(M_PI / 60)) + (map[i].z * cos(M_PI / 60));
		i++;
	}
	while (map[i].color && s == -2)
	{
		tmp = map[i].x;
		map[i].x = (map[i].x * cos(-M_PI / 60)) + (map[i].z * sin(-M_PI / 60));
		map[i].z = - (tmp * sin(-M_PI / 60)) + (map[i].z * cos(-M_PI / 60));
		i++;
	}
	return (map);
}

t_pixel	*rotation_z(t_pixel *map, int s)
{
	int		i;
	double	tmp;

	i = 0;
	while (map[i].color && s == 3)
	{
		tmp = map[i].x;
		map[i].x = (map[i].x * cos(M_PI / 60)) - (map[i].y * sin(M_PI / 60));
		map[i].y = (tmp * sin(M_PI / 60)) + (map[i].y * cos(M_PI / 60));
		i++;
	}
	while (map[i].color && s == -3)
	{
		tmp = map[i].x;
		map[i].x = (map[i].x * cos(-M_PI / 60)) - (map[i].y * sin(-M_PI / 60));
		map[i].y = (tmp * sin(-M_PI / 60)) + (map[i].y * cos(-M_PI / 60));
		i++;
	}
	return (map);
}

t_pixel	*ft_rotation(t_pixel *map, int projection)
{
	if (projection == 1 || projection == -1)
		map = rotation_x(map, projection);
	if (projection == 2 || projection == -2)
		map = rotation_y(map, projection);
	if (projection == 3 || projection == -3)
		map = rotation_z(map, projection);
	return (map);
}
