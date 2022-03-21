/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:14:47 by pat               #+#    #+#             */
/*   Updated: 2022/03/21 16:02:11 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(int argc, char **argv)
{
	t_data		img;
	t_win		w;

	(void)img;
	(void)argc;
	w.name = argv[1];
	w.height = ft_atoi(argv[2]);
	w.width = ft_atoi(argv[3]);
	w.namew = argv[4];
	if (!argv[4])
		w.namew = argv[1];
	w.draw_color = 1;
	w.draw_map_color = 1;
	w.stop = 0;
	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.width, w.height, w.namew);
	img.img = mlx_new_image(w.mlx_ptr, w.width, w.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	w.ref = ft_ref(w);
	w.map = ft_parsing(&w);
	w.img = img.img;
	w.map = ft_set(w.map, w);
	ft_draw(&w);
	mlx_key_hook(w.win_ptr, ft_keyhook, &w);
	mlx_loop(w.mlx_ptr);

	return (0);
}
