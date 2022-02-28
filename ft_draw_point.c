/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:30:09 by pat               #+#    #+#             */
/*   Updated: 2022/02/28 13:51:53 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_point(t_win *w)
{
	int			i;

	i = 0;
	while (w->map[i].color)
	{
		mlx_pixel_put(w->mlx_ptr, w->win_ptr, ft_round(w->map[i].x + w->ref.x),
			ft_round(w->map[i].y + w->ref.y),0x00FFFFFF);
		i++;
	}
}