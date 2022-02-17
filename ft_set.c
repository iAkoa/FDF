/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:14:37 by pat               #+#    #+#             */
/*   Updated: 2022/02/17 18:48:02 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

t_pixel	*ft_set(t_pixel *map, t_win s)
{
	int	i;
	int	j;
	
	j = 0;
	i = 0;
	s.height = s.height;
	while (map[i].color)
		i++;
	// while (j < 10)
	// {
	// 	map = ft_rotation(map, 1);
	// 	map = ft_rotation(map, 2);
	// 	map = ft_rotation(map, 3);
	// 	j++;
	// }
	while (fabs(map[i - 1].x) < (double)s.height/4)
	{
		map = ft_zoom(map, 1, *map);
	}
	return (map);
}