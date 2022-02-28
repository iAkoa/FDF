/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:37:54 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/27 19:40:10 by pat              ###   ########lyon.fr   */
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
		// mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
		mlx_new_image(w->mlx_ptr, w->width, w->height);
		ft_draw(w, w->x_max, w->y_max);
	}
	if (keycode == DOWN_ARROW)
	{
		w->map = ft_translation(w->map, 1);
		// mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
		mlx_new_image(w->mlx_ptr, w->width, w->height);
		ft_draw(w, w->x_max, w->y_max);
	}
	if (keycode == LEFT_ARROW)
	{
		w->map = ft_translation(w->map, 4);
		// mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
		mlx_new_image(w->mlx_ptr, w->width, w->height);
		ft_draw(w, w->x_max, w->y_max);
	}
	if (keycode == RIGHT_ARROW)
	{
		w->map = ft_translation(w->map, 3);
		// mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
		mlx_new_image(w->mlx_ptr, w->width, w->height);
		ft_draw(w, w->x_max, w->y_max);
	}
	if (keycode == MORE || keycode == T)
	{
		t_pixel	x;

		x.x = 0;
		w->map = ft_zoom(w->map, 1, x);
		// mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
		mlx_new_image(w->mlx_ptr, w->width, w->height);
		ft_draw(w, w->x_max, w->y_max);
	}
	if (keycode == LESS || keycode == R)
	{
		t_pixel	x;

		x.x = 0;
		w->map = ft_zoom(w->map, -1, x);
		// mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
		mlx_new_image(w->mlx_ptr, w->width, w->height);
		ft_draw(w, w->x_max, w->y_max);
	}
	if (keycode == ONE_NUM_PAD || keycode == Q)
	{
		w->map = ft_rotation(w->map, 1);
		// mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
		mlx_new_image(w->mlx_ptr, w->width, w->height);
		ft_draw(w, w->x_max, w->y_max);
	}
	if (keycode == TWO_NUM_PAD || keycode == W)
	{
		w->map = ft_rotation(w->map, 2);
		// mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
		mlx_new_image(w->mlx_ptr, w->width, w->height);
		ft_draw(w, w->x_max, w->y_max);
	}
	if (keycode == THREE_NUM_PAD || keycode == E)
	{
		w->map = ft_rotation(w->map, 3);
		// mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
		mlx_new_image(w->mlx_ptr, w->width, w->height);
		ft_draw(w, w->x_max, w->y_max);
	}
	if (keycode == SIX_NUM_PAD || keycode == A)
	{
		w->map = ft_rotation(w->map, -3);
		// mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
		mlx_new_image(w->mlx_ptr, w->width, w->height);
		ft_draw(w, w->x_max, w->y_max);
	}
	if (keycode == FIVE_NUM_PAD || keycode == S)
	{
		w->map = ft_rotation(w->map, -2);
		// mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
		mlx_new_image(w->mlx_ptr, w->width, w->height);
		ft_draw(w, w->x_max, w->y_max);
	}
	if (keycode == FOUR_NUM_PAD || keycode == D)
	{
		w->map = ft_rotation(w->map, -1);
		// mlx_destroy_image(w->mlx_ptr, w->win_ptr);
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
		mlx_new_image(w->mlx_ptr, w->width, w->height);
		ft_draw(w, w->x_max, w->y_max);
	}
	return (0);
}
