/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:44:39 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/10 17:53:23 by rmattheo         ###   ########lyon.fr   */
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

typedef struct s_vector
{
	t_pixel	p1;
	t_pixel	p2;
	int		norm;
	double	dx;
	double	dy;
	double	dz;
	double	sx;
	double	sy;
	double	sz;
	double	e2;
	int		color;
}				t_vector;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	t_pixel	ref;
}				t_win;

typedef struct s_pars
{
	char	**split;
	char	*line;
}				t_pars;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_pixel		*ft_parsing(char *mapargv);
t_pixel		*ft_zoom(t_pixel *map, int zoom);
t_data		ft_bresenham(t_vector vector, t_data win, t_pixel ref);
t_vector	ft_utils(t_pixel	p1, t_pixel	p2);
t_pixel		*ft_projection(t_pixel *map);
t_pixel		*ft_rotation(t_pixel *map, int projection);
t_pixel		ft_ref(t_win h, t_win w);

#endif
