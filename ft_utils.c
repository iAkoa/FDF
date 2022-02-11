/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:24:53 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/10 16:00:13 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	compare(double i, double j)
{
	if (i - j > 0)
		return (1);
	return (-1);
}

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_vector	ft_utils(t_pixel	p1, t_pixel	p2)
{
	t_vector	vector;

	vector.p1.x = (int)p1.x;
	vector.p1.y = (int)p1.y;
	vector.p2.x = (int)p2.x;
	vector.p2.y = (int)p2.y;
	vector.dx = ft_abs(vector.p2.x - vector.p1.x);
	vector.sx = compare(vector.p1.x, vector.p2.x);
	vector.dy = -ft_abs(vector.p2.y - vector.p1.y);
	vector.sy = compare(vector.p1.y, vector.p2.y);
	vector.dz = ft_abs(vector.p2.z - vector.p1.z);
	vector.sz = compare(vector.p1.z, vector.p2.z);
	return (vector);
}
