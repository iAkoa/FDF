/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:07:00 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/28 19:46:04 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

int pythagore (t_pixel p1, t_pixel p2)
{
	return(sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}

void	ft_bresenham(t_vector vector, t_win *w, t_pixel ref)
{
	int			err;
	t_pixel		p1;
	t_pixel		p;

	p1.y = ft_round(vector.p1.y + ref.y);
	p1.x = ft_round(vector.p1.x + ref.x);

	p.y = ft_round(vector.p1.y);
	p.x = ft_round(vector.p1.x);
	err = ft_round(vector.dx + vector.dy);
	while (1)
	{
		if (vector.p1.y + ref.y >= 0 && vector.p1.y + ref.y < w->height
			&& vector.p1.y + ref.x >= 0 && vector.p1.x + ref.x < w->width)
			mlx_pixel_put(w->mlx_ptr, w->win_ptr, ft_round(vector.p1.x + ref.x), ft_round(vector.p1.y + ref.y), ft_color_bresenham(vector.p1.z_originel, vector.p2.z_originel, 1 - ((double)pythagore(vector.p1,vector.p2) / (double)pythagore(p, vector.p2)), w));
		if (ft_round(vector.p1.x) == ft_round(vector.p2.x)
			&& ft_round(vector.p1.y) == ft_round(vector.p2.y))
			break ;
		vector.e2 = 2 * err;
		if (vector.e2 >= vector.dy)
		{
			err += vector.dy;;
			vector.p1.x += vector.sx;
		}
		if (vector.e2 <= vector.dx)
		{
			err += vector.dx;
			vector.p1.y += vector.sy;
		}
	}
}
