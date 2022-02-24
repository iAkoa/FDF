/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:07:00 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/23 16:08:39 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void	ft_bresenham(t_vector vector, t_win *w, t_pixel ref)
{
	int			err;
	
	t_pixel p1;
	p1.y = ft_round(vector.p1.y + ref.y);
	p1.x = ft_round(vector.p1.x + ref.x);
	err = ft_round(vector.dx + vector.dy);
	while (1)
	{
		// printf("p1.y = %f\n",  p1.y);
		// printf("heigth = %i\n", w->height);
		if (vector.p1.y + ref.y >= 0 && vector.p1.y + ref.y < w->height 
			&& vector.p1.y + ref.x >= 0 && vector.p1.x + ref.x < w->width)
				mlx_pixel_put(w->mlx_ptr,w->win_ptr, ft_round(vector.p1.x
					+ ref.x), ft_round(vector.p1.y + ref.y), 0x00FFFFFF);
		if (ft_round(vector.p1.x) == ft_round(vector.p2.x) && ft_round(vector.p1.y) == ft_round(vector.p2.y))
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
	return ;
}
