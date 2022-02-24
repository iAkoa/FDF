/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:44:39 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/23 15:18:30 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include "mlx/mlx.h"
# include <math.h>
//include "minilibx/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		*x_max;
	int		*y_max;
}				t_data;

typedef struct s_pixel
{
	double	x;
	double	y;
	double	z;
	int		color;
	int		line;
	int		column;
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
t_pixel		*ft_parsing(char *mapargv, int *y_max, int *x_max);
t_pixel		*ft_zoom(t_pixel *map, int zoom, t_pixel xy);
void		ft_bresenham(t_vector vector, t_win *w, t_pixel ref);
t_vector	ft_utils(t_pixel	p1, t_pixel	p2);
t_pixel		*ft_projection(t_pixel *map);
t_pixel		*ft_rotation(t_pixel *map, int projection);
t_pixel		ft_ref(t_win w);
t_pixel		*ft_set(t_pixel *map, t_win s);

#endif
