/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:30:09 by pat               #+#    #+#             */
/*   Updated: 2022/03/01 01:37:18 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_point(t_win *w)
{
	int	i;

	i = 0;
	while (i < (w->x_max * w->y_max))
	{
		mlx_pixel_put(w->mlx_ptr, w->win_ptr, ft_round(w->map[i].x + w->ref.x),
			ft_round(w->map[i].y + w->ref.y),w->map[i].color);
		i++;
	}
}
