/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:14:47 by pat               #+#    #+#             */
/*   Updated: 2022/02/04 00:21:11 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		img;
	t_pixel		*map;
	t_window	w;
	int			i;
	(void)argc;
	w.height = ft_atoi(argv[2]);
	w.width = ft_atoi(argv[3]);
	i = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, w.height,w.width, "test_mlx");
	img.img = mlx_new_image(mlx_ptr, w.height, w.width);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	map = ft_parcing(argv[1]);
	map = ft_zoom(map, w.height, w.width);
	while (map[i].exit)
	{
		my_mlx_pixel_put(&img, ft_round(map[i].x), ft_round(map[i].y), ft_round(map[i].color));
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}
