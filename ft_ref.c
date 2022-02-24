/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ref.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:27:36 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/23 15:33:44 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	ft_ref(t_win w)
{
	t_pixel	r;

	r.y = w.height / 2;
	r.x = w.width / 2;
	return (r);
}
