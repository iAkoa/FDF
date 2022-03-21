/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:37:54 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/19 03:48:44 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	ft_keyhook(int keycode, t_win *w)
{
	ft_keyhook1(keycode, w);
	ft_keyhook2(keycode, w);
	ft_keyhook3(keycode, w);
	ft_keyhook4(keycode, w);
	ft_keyhook5(keycode, w);
	return (0);
}
