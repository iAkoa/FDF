/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:30:09 by pat               #+#    #+#             */
/*   Updated: 2022/05/26 17:16:10 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

// void	ft_draw_point(t_win *w)
// {
// 	int	i;

// 	i = 0;
// 	while (i < (w->x_max * w->y_max))
// 	{
// 		mlx_pixel_put(w->mlx_ptr, w->win_ptr, ft_round(w->map[i].x + w->ref.x),
// 			ft_round(w->map[i].y + w->ref.y), w->map[i].color);
// 		i++;
// 	}
// }

void	ft_draw_point(t_win *w)
{
	int	i;

	i = 0;
	while (i < (w->x_max * w->y_max -1))
	{
		ft_my_mlx_pixel_put(w, ft_round(w->map[i].x + w->ref.x),
			ft_round(w->map[i].y + w->ref.y), w->map[i].color);
		i++;
	}
}
