/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:14:47 by pat               #+#    #+#             */
/*   Updated: 2022/02/24 16:18:02 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"


int	main(int argc, char **argv)
{
	t_data		img;
	t_win		w;
	int			i;
	int			y_max;
	int			x_max;


	(void)argc;
	w.height = ft_atoi(argv[2]);
	w.width = ft_atoi(argv[3]);
	i = 0;
	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.width, w.height, "test_mlx");
	img.img = mlx_new_image(w.mlx_ptr, w.width, w.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	w.ref = ft_ref(w);
	w.map = ft_parsing(argv[1], &y_max, &x_max);
	w.x_max = x_max;
	w.y_max = y_max;
	w.map = ft_set(w.map, w);
	ft_draw(&w, x_max, y_max);
	mlx_key_hook(w.win_ptr, ft_keyhook, &w);
	mlx_loop(w.mlx_ptr);
}
