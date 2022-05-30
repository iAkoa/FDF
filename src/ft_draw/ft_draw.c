/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:27:29 by rmattheo          #+#    #+#             */
/*   Updated: 2022/05/27 17:38:36 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_draw(t_win *w)
{
	int			i;
	t_vector	v;

	i = 0;
	ft_my_pixel_clear(w);
	if (w->draw_point == 1)
	{
		while (w->map[i].color)
		{
			if (w->map[i + 1].color && (i + 1) % w->x_max != 0)
			{
				v = ft_utils(w->map[i], w->map[i + 1]);
				ft_bresenham(v, w, w->ref);
			}
			if (w->map[i + 1].color && i / w->x_max != w->y_max - 1)
			{
				v = ft_utils(w->map[i], w->map[i + w->x_max]);
				ft_bresenham(v, w, w->ref);
			}
			i++;
		}
	}
	else
		ft_draw_point(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->image.img, 0, 0);
}
