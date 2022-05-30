/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:14:37 by pat               #+#    #+#             */
/*   Updated: 2022/05/27 17:36:53 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_pixel	*ft_set(t_pixel *map, t_win s)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (++j < 15)
		map = ft_rotation(map, 1);
	j = -1;
	while (++j < 10)
		map = ft_rotation(map, -2);
	j = -1;
	while (++j < 10)
		map = ft_rotation(map, 3);
	while (fabs(map[s.x_max].x) < (double)s.height / 4
		&& fabs(map[s.y_max].y) < (double)s.width / 4
		&& (s.x_max > 1 && s.y_max > 1))
	{
		map = ft_zoom(map, 1, &s);
	}
	return (map);
}
