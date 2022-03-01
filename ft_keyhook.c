/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:37:54 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/01 03:30:02 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_keyhook(int keycode, t_win *w)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		exit(0);
	}
	if (keycode == UP_ARROW)
	{
		w->map = ft_translation(w->map, 2);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == DOWN_ARROW)
	{
		w->map = ft_translation(w->map, 1);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == LEFT_ARROW)
	{
		w->map = ft_translation(w->map, 4);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == RIGHT_ARROW)
	{
		w->map = ft_translation(w->map, 3);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == MORE || keycode == T)
	{
		t_pixel	x;

		x.x = 0;
		w->map = ft_zoom(w->map, 1, x);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == LESS || keycode == R)
	{
		t_pixel	x;

		x.x = 0;
		w->map = ft_zoom(w->map, -1, x);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == ONE_NUM_PAD || keycode == Q)
	{
		w->map = ft_rotation(w->map, 1);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == TWO_NUM_PAD || keycode == W)
	{
		w->map = ft_rotation(w->map, 2);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == THREE_NUM_PAD || keycode == E)
	{
		w->map = ft_rotation(w->map, 3);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == SIX_NUM_PAD || keycode == A)
	{
		w->map = ft_rotation(w->map, -3);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == FIVE_NUM_PAD || keycode == S)
	{
		w->map = ft_rotation(w->map, -2);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == FOUR_NUM_PAD || keycode == D)
	{
		w->map = ft_rotation(w->map, -1);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == P)
	{
		w->draw_point = -w->draw_point;
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == C)
	{
		w->draw_color = -w->draw_color;
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == X)
	{
		w->draw_map_color = -w->draw_map_color;
		ft_keyhook_process(w);
		ft_draw(w);
	}
	return (0);
}
