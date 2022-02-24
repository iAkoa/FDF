/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:14:47 by pat               #+#    #+#             */
/*   Updated: 2022/02/23 17:24:20 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	t_data		img;
	t_pixel		*map;
	t_win		w;
	t_vector	v;
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
	/*              */
	w.ref = ft_ref(w);
	map = ft_parsing(argv[1], &y_max, &x_max);
	map = ft_set(map, w);
	// while (map[i].color)
	// {
	// 	printf("map.x = %f, map.y = %f, map.z = %f\n", map[i].x, map[i].y, map[i].z);
	// 	i++;
	// }
	// i = 0;
	while (map[i].color)
	{
		// printf("map.x = %f, map.y = %f\n", map[i].x, map[i].y);
		// printf("map.x = %f, map.y = %f\n", map[i + 1].x, map[i + 1].y);
		// printf("y_max = %i x_max = %i\n", y_max, x_max);
		if (map[i + 1].color && (i + 1) % x_max != 0)
		{
			v = ft_utils(map[i], map[i + 1]);
			ft_bresenham(v, &w, w.ref);
		}
		if (map[i + 1].color && i / x_max != y_max - 1)
		{
			v = ft_utils(map[i], map[i + x_max]);
			ft_bresenham(v, &w, w.ref);
		}
		// if ((ft_round(map[i].x) + w.ref.x) < w.height || (ft_round(map[i].y) + w.ref.y) < w.width)
		// {
		// 	// printf("map.x = %f, map.y = %f\n", (int)ft_round(map[i].x) + w.ref.x, (int)ft_round(map[i].y) + w.ref.y);
		// 	mlx_pixel_put(w.mlx_ptr, w.win_ptr, (int)ft_round(map[i].x) + w.ref.x,
		// 		(int)ft_round(map[i].y) + w.ref.y, 0x00ffffff);
		// }
		i++;
	}
	/*              */
	//mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, img.img, 0, 0);
	mlx_loop(w.mlx_ptr);
}