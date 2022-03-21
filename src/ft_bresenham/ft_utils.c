/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:24:53 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/18 17:32:01 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

double	compare(double i, double j)
{
	if (j - i > 0)
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

	vector.p1.x = (int)ft_round(p1.x);
	vector.p2.x = (int)ft_round(p2.x);
	vector.p1.y = (int)ft_round(p1.y);
	vector.p2.y = (int)ft_round(p2.y);
	vector.p1.z = (int)ft_round(p1.z);
	vector.p2.z = (int)ft_round(p2.z);
	vector.p1.color = p1.color;
	vector.p2.color = p2.color;
	vector.p1.z_originel = p1.z_originel;
	vector.p2.z_originel = p2.z_originel;
	vector.dx = ft_abs(vector.p2.x - vector.p1.x);
	vector.sx = compare(vector.p1.x, vector.p2.x);
	vector.dy = -ft_abs(vector.p2.y - vector.p1.y);
	vector.sy = compare(vector.p1.y, vector.p2.y);
	vector.dz = ft_abs(vector.p2.z - vector.p1.z);
	vector.sz = compare(vector.p1.z, vector.p2.z);
	return (vector);
}
