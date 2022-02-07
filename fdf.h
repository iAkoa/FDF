/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:44:39 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/07 00:55:52 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include "mlx/mlx.h"
# include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_pixel
{
	double	x;
	double	y;
	double	z;
	int		color;
	int		exit;
}				t_pixel;

typedef struct s_window
{
	int		height;
	int		width;
}				t_window;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_pixel	*ft_parcing(char *mapargv);
t_pixel *ft_zoom(t_pixel *map, int zoom);

#endif
