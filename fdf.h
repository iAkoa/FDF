/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:44:39 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/24 13:42:54 by rmattheo         ###   ########lyon.fr   */
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
	t_pixel	*map;
	int		y_max;
	int		x_max;
}				t_win;

typedef struct s_pars
{
	char	**split;
	char	*line;
	
}				t_pars;

# define ESC 53

# define A 0
# define B 11
# define C 8
# define D 2
# define E 4
# define F 3
# define G 9
# define H 4
# define I 34
# define J 38
# define K 40
# define L 37
# define M 46
# define N 45
# define O 31
# define P 35
# define Q 12
# define R 15
# define S 1
# define T 17
# define U 32
# define V 9
# define W 13
# define X 7
# define Y 16
# define Z 6

# define ONE_NUM_PAD 83
# define TWO_NUM_PAD 84
# define THREE_NUM_PAD 85
# define FOUR_NUM_PAD 86
# define FIVE_NUM_PAD 87
# define SIX_NUM_PAD 88
# define SEVEN_NUM_PAD 89
# define EIGHT_NUM_PAD 91
# define NINE_NUM_PAD 92

# define LESS 78
# define MORE 69

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_pixel		*ft_parsing(char *mapargv, int *y_max, int *x_max);
t_pixel		*ft_zoom(t_pixel *map, int zoom, t_pixel xy);
void		ft_bresenham(t_vector vector, t_win *w, t_pixel ref);
t_vector	ft_utils(t_pixel	p1, t_pixel	p2);
t_pixel		*ft_projection(t_pixel *map);
t_pixel		*ft_rotation(t_pixel *map, int projection);
t_pixel		ft_ref(t_win w);
t_pixel		*ft_set(t_pixel *map, t_win s);
t_pixel		*ft_translation(t_pixel *map, int mod);
void		ft_draw(t_win *w, int x_max, int y_max);
int			ft_keyhook(int keycode, t_win *w);

#endif
