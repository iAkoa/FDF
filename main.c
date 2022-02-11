/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:14:47 by pat               #+#    #+#             */
/*   Updated: 2022/02/10 16:05:03 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data		img;
	t_pixel		*map;
	t_win		w;
	t_vector	v;
	int			i;

	(void)argc;
	w.height = ft_atoi(argv[2]);
	w.width = ft_atoi(argv[3]);
	i = 0;
	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.height, w.width, "test_mlx");
	img.img = mlx_new_image(w.mlx_ptr, w.height, w.width);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	/*              */
	w.ref = ft_ref(w, w);
	map = ft_parsing(argv[1]);
	i = ft_strlen((int)map[i].x);
	while (map[i].x <= (double)w.height / 1.5
		&& map[i].y <= (double)w.width / 1.5)
	{
		ft_zoom(map, 1);
		i++;
	}
	i = 0;
	while (map[i].exit)
	{
		if (map[i + 1].x)
			v = ft_utils(map[i], map[i + 1]);
		ft_bresenham(v, img, w.ref);
		my_mlx_pixel_put(&img, ft_round(map[i].x) + w.ref.x,
			ft_round(map[i].y) + w.ref.y, ft_round(map[i].color));
		i++;
	}
	/*              */
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, img.img, 0, 0);
	mlx_loop(w.mlx_ptr);
}
