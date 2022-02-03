/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:14:47 by pat               #+#    #+#             */
/*   Updated: 2022/02/03 21:43:12 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fdf.h"
#include <math.h>

int	main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		img;
	t_pixel		*map;
	(void)argc;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test_mlx");
	img.img = mlx_new_image(mlx_ptr, 500, 500);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	map = ft_parcing(argv[1]);
	while (map->exit)
	{
		my_mlx_pixel_put(&img, map->x, map->y, 0x00FF00FF);
		map++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}
