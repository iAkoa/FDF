/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:14:47 by pat               #+#    #+#             */
/*   Updated: 2022/05/30 18:58:48 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static int	ft_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

static void	set_main(t_win *w, int argc, char **argv)
{
	if (argc < 4 || argc > 6)
		exit(0);
	w->draw_point = 1;
	w->draw_color = 1;
	w->draw_map_color = 1;
	w->stop = 0;
	w->z_no_color = 0;
	w->track = NULL;
	w->name = argv[1];
	w->height = ft_atoi(argv[2]);
	w->width = ft_atoi(argv[3]);
}

int	main(int argc, char **argv)
{
	t_win		w;

	set_main(&w, argc, argv);
	if (argc == 5)
		w.namew = argv[4];
	else
		w.namew = "fdf";
	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.width, w.height, w.namew);
	w.image.img = mlx_new_image(w.mlx_ptr, w.width, w.height);
	w.image.addr = mlx_get_data_addr(w.image.img, &w.image.bits_per_pixel,
			&w.image.line_length, &w.image.endian);
	w.ref = ft_ref(w);
	w.map = ft_parsing(&w);
	w.map = ft_set(w.map, w);
	w.img = w.image.img;
	ft_draw(&w);
	mlx_hook(w.win_ptr, 2, 1L << 0, ft_keyhook, &w);
	mlx_hook(w.win_ptr, 17, 0, ft_exit, &w);
	mlx_loop(w.mlx_ptr);
	return (0);
}
