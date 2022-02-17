/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:14:47 by pat               #+#    #+#             */
/*   Updated: 2022/02/17 18:07:34 by pat              ###   ########lyon.fr   */
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
	map = ft_set(map, w);
	// while (map[i].color)
	// {
	// 	printf("map.x = %f, map.y = %f, map.z = %f\n", map[i].x, map[i].y, map[i].z);
	// 	i++;
	// }
	// i = 0;
	while (map[i].color)
	{
		if (map[i + 1].color)
			v = ft_utils(map[i], map[i + 1]);
		img = ft_bresenham(v, img, w.ref);
		if ((ft_round(map[i].x) + w.ref.x) < w.height || (ft_round(map[i].y) + w.ref.y) < w.width)
			my_mlx_pixel_put(&img, ft_round(map[i].x) + w.ref.x,
				ft_round(map[i].y) + w.ref.y, ft_round(map[i].color));
		i++;
	}
	/*              */
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, img.img, 0, 0);
	mlx_loop(w.mlx_ptr);
}