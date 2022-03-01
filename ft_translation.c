/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:39:00 by pat               #+#    #+#             */
/*   Updated: 2022/02/28 23:04:45 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	*ft_translation_up(t_pixel *map)
{
	int	i;

	i = 0;
	while (map[i].color)
	{
		map[i].y += 50;
		i++;
	}
	return (map);
}

t_pixel	*ft_translation_down(t_pixel *map)
{
	int	i;

	i = 0;
	while (map[i].color)
	{
		map[i].y -= 50;
		i++;
	}
	return (map);
}

t_pixel	*ft_translation_left(t_pixel *map)
{
	int	i;

	i = 0;
	while (map[i].color)
	{
		map[i].x -= 50;
		i++;
	}
	return (map);
}

t_pixel	*ft_translation_right(t_pixel *map)
{
	int	i;

	i = 0;
	while (map[i].color)
	{
		map[i].x += 50;
		i++;
	}
	return (map);
}

t_pixel	*ft_translation(t_pixel *map, int mod)
{
	if (mod == 1)
		ft_translation_up(map);
	if (mod == 2)
		ft_translation_down(map);
	if (mod == 3)
		ft_translation_right(map);
	if (mod == 4)
		ft_translation_left(map);
	return (map);
}
