/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:30:09 by pat               #+#    #+#             */
/*   Updated: 2022/05/27 17:13:49 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_draw_point(t_win *w)
{
	int	i;

	i = 0;
	while (i < (w->x_max * w->y_max))
	{
		ft_my_mlx_pixel_put(w, ft_round(w->map[i].x + w->ref.x),
			ft_round(w->map[i].y + w->ref.y), w->map[i].color);
		i++;
	}
}
