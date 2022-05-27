/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_pixel_clear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:54:16 by rmattheo          #+#    #+#             */
/*   Updated: 2022/05/27 14:08:30 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_my_pixel_clear(t_win *w)
{
	int	x;
	int	y;

	x = 0;
	while (x < w->width)
	{
		y = 0;
		while (y < w->height)
		{
			ft_my_mlx_pixel_put(w, x, y, 0);
			y++;
		}
		x++;
	}
}
