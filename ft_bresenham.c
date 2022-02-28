/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:07:00 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/27 19:34:25 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void	ft_bresenham(t_vector vector, t_win *w, t_pixel ref)
{
	int			err;
	t_pixel		p1;

	p1.y = ft_round(vector.p1.y + ref.y);
	p1.x = ft_round(vector.p1.x + ref.x);
	err = ft_round(vector.dx + vector.dy);
	printf("color vector = %i\n", vector.p1.color);
	while (1)
	{
		if (vector.p1.y + ref.y >= 0 && vector.p1.y + ref.y < w->height
			&& vector.p1.y + ref.x >= 0 && vector.p1.x + ref.x < w->width)
			mlx_pixel_put(w->mlx_ptr, w->win_ptr, ft_round(vector.p1.x
					+ ref.x), ft_round(vector.p1.y + ref.y),
				ft_colinterpolate(vector.p1.color, vector.p2.color, 50/100));
		if (ft_round(vector.p1.x) == ft_round(vector.p2.x)
			&& ft_round(vector.p1.y) == ft_round(vector.p2.y))
			break ;
		vector.e2 = 2 * err;
		if (vector.e2 >= vector.dy)
		{
			err += vector.dy;
			vector.p1.x += vector.sx;
			// vector.p1.y += vector.sy;
		}
		if (vector.e2 <= vector.dx)
		{
			err += vector.dx;
			vector.p1.y += vector.sy;
			// vector.p1.z += vector.sz;
		}
		// if (vector.e2 <= vector.dz)
		// {
		// 	err += vector.dz;
		// 	vector.p1.y += vector.sy;
		// 	vector.p1.x += vector.sx;
		// }
	}
	return ;
}
