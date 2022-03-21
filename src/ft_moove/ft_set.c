/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:14:37 by pat               #+#    #+#             */
/*   Updated: 2022/03/19 03:37:48 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_pixel	*ft_set(t_pixel *map, t_win s)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (map[i].color)
		i++;
	while (++j < 15)
		map = ft_rotation(map, 1);
	j = -1;
	while (++j < 10)
		map = ft_rotation(map, -2);
	j = -1;
	while (++j < 10)
		map = ft_rotation(map, 3);
	while (fabs(map[i - 1].x) < (double)s.height
		/ 4 && fabs(map[i - 1].y) < (double)s.width / 4)
		map = ft_zoom(map, 1, *map);
	return (map);
}
