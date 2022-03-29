/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:44:39 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/29 01:44:57 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft2/include/libft.h"
# include "../libft2/include/gc.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

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
	double	z_originel;
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
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	t_pixel	ref;
	t_pixel	*map;
	int		y_max;
	int		x_max;
	double	z_max;
	double	z_min;
	char	*namew;
	char	*name;
	int		draw_point;
	int		draw_color;
	int		draw_map_color;
	int		z_no_color;
	double	z_compare;
	t_track	*track;
	int		stop;
	int		i;
	t_pixel	p;
}				t_win;

typedef struct s_pars
{
	char	*line;
	char	*line2;
	char	**split_tab;
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
t_pixel		*ft_parsing(t_win *w);
t_pixel		*ft_zoom(t_pixel *map, int zoom, t_win *w);
void		ft_bresenham(t_vector vector, t_win *w, t_pixel ref);
t_vector	ft_utils(t_pixel	p1, t_pixel	p2);
t_pixel		*ft_rotation(t_pixel *map, int projection);
t_pixel		ft_ref(t_win w);
t_pixel		*ft_set(t_pixel *map, t_win s);
t_pixel		*ft_translation(t_pixel *map, int mod);
void		ft_draw(t_win *w);
int			ft_keyhook(int keycode, t_win *w);
void		ft_keyhook_process(t_win *w);
void		ft_draw_point(t_win *w);
void 		ft_full_white(t_pixel *map,t_win *w);
void		ft_color(t_pixel *map, t_win *w);
int			ft_color_bresenham(double z1, double z2, double per, t_win *w);
void		ft_free_while(t_win *w, t_pars *p);
void		ft_color_25less(t_pixel *map, t_win *w);
void		ft_keyhook1(int keycode, t_win *w);
void		ft_keyhook2(int keycode, t_win *w);
void		ft_keyhook3(int keycode, t_win *w);
void		ft_keyhook4(int keycode, t_win *w);
void		ft_keyhook5(int keycode, t_win *w);

#endif
