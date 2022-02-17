/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:07:00 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/17 18:03:19 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

t_data	ft_bresenham(t_vector vector, t_data win, t_pixel ref)
{
	int			err;
	t_win		w;
	err = vector.dx + vector.dy;
	while (1)
	{
		if (vector.p1.y + ref.y >= 0 && vector.p1.y + ref.y < w.height
			&& vector.p1.x + ref.x >= 0 && vector.p1.x + ref.x < w.width)
			my_mlx_pixel_put(&win, vector.p1.x
				+ ref.x, vector.p1.y + ref.y, 0x00FFFFFF);
		if (vector.p1.x == vector.p2.x && vector.p1.y == vector.p2.y)
			break ;
		vector.e2 = 2 * err;
		if (vector.e2 >= vector.dy)
		{
			err += vector.dy;
			vector.p1.x += vector.sx;
		}
		if (vector.e2 <= vector.dx)
		{
			err += vector.dx;
			vector.p1.y += vector.sy;
		}
	}
	return (win);
}
