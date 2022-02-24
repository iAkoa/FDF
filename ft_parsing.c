/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:31:27 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/23 15:45:03 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int ft_size_map(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(line[i] == ' ')
		i++;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ' && line[i + 1] != '\n' && line[i + 1] != ' ')
			count++;
		i++;
	}
	return (count + 1);
}
static t_pixel	*ft_malloc_map(int fd, int *y_max, int *x_max)
{
	char	*line;
	t_pixel	*map;
	int		i;
	
	i = 0;
	*y_max = 0;
	*x_max = 0;
	line = get_next_line(fd);
	if (line)
		*y_max+=1;
	i = ft_size_map(line);\
	*x_max = i;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			*y_max+=1;

	}
	i *= *y_max;
	printf("x_max = %i\n", *x_max);
	printf("y_max = %i\n", *y_max);
	map = ft_calloc(i , sizeof(t_pixel));
	if (!map)
		return (0);
	return (map);
}

t_pixel	*creat_map(t_pixel *map, char **split_tab, int y, int x_max, int y_max)
{
	double	x;
	int		i;
	x = 0;
	i = 0;
	
	while (split_tab[i])
	{
		map->z = (double)ft_atoi(split_tab[i]);
		map->x = x - (double)x_max;
		map->y = y - (double)y_max;
		map->color = 0x00FFFFFF;
		map++;
		x++;
		i++;
	}
	return (map);
}

t_pixel	*ft_parsing(char *mapargv, int *y_max, int *x_max)
{
	int		fd;
	char	*line;
	char	**line2;
	char	**split_tab;
	t_pixel	*map;
	t_pixel	*tmp;
	double	y;

	y = 0;
	fd = open(mapargv, O_RDONLY);
	map = ft_malloc_map(fd, y_max, x_max);
	tmp = map;
	close(fd);
	fd = open(mapargv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line2 = ft_split(line, '\n');
		split_tab = ft_split(*line2, ' ');
		// int i = -1;
		// int j = -1;
		// while (split_tab[++i])
		// 	// while (split_tab[i][++j]);
		// 		printf("split_tab = %c\n", split_tab[i][0]);
		map = creat_map(map, split_tab, y, *x_max/2, *y_max/2);
		if (!map)
			return (NULL);
		line = get_next_line(fd);
		y++;
	}
	// int i = -1;
	// while (tmp[++i].color)
	// 	printf ("tmp = %f, i = %d\n", tmp[i].x, i);
	return (tmp);
}
