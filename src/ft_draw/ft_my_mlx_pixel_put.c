/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_mlx_pixel_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:27:58 by rmattheo          #+#    #+#             */
/*   Updated: 2022/05/27 14:08:09 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_my_mlx_pixel_put(t_win *w, int x, int y, int color)
{
	char	*dst;

	if (x > w->width || y > w->height || x < 0 || y < 0)
		return ;
	dst = w->image.addr + (y * w->image.line_length
			+ x * (w->image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
