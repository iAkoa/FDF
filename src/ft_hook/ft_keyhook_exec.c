/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 03:44:17 by pat               #+#    #+#             */
/*   Updated: 2022/05/26 16:07:01 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_keyhook1(int keycode, t_win *w)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(w->mlx_ptr, w->img);
		mlx_destroy_window(w->mlx_ptr, w->win_ptr);
		gc_free_all(&w->track);
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
}

void	ft_keyhook2(int keycode, t_win *w)
{
	if (keycode == RIGHT_ARROW)
	{
		w->map = ft_translation(w->map, 3);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == MORE || keycode == T)
	{
		w->map = ft_zoom(w->map, 1, w);
		ft_keyhook_process(w);
		ft_draw(w);
	}
	if (keycode == LESS || keycode == R)
	{
		w->map = ft_zoom(w->map, -1, w);
		ft_keyhook_process(w);
		ft_draw(w);
	}
}

void	ft_keyhook3(int keycode, t_win *w)
{
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
}

void	ft_keyhook4(int keycode, t_win *w)
{
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
}

void	ft_keyhook5(int keycode, t_win *w)
{
	if (keycode == X)
	{
		w->draw_map_color = -w->draw_map_color;
		ft_keyhook_process(w);
		ft_draw(w);
	}
}
