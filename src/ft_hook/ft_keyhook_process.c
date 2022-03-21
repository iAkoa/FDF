/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:54:48 by pat               #+#    #+#             */
/*   Updated: 2022/03/19 03:49:43 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_keyhook_process(t_win *w)
{
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	mlx_new_image(w->mlx_ptr, w->width, w->height);
}
