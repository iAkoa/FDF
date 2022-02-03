/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:31:27 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/03 19:09:09 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int ft_size_map(char **split_tab)
{
	int	i;

	i = 0;
	while (split_tab[i])
		i++;
	return (i);
}
static t_pixel	*ft_malloc_map(int fd)
{
	char	*line;
	t_pixel	*map;
	int		i;
	char	**split_tab;

	i = 0;
	map = ft_calloc(sizeof(t_pixel), 1);
	line = get_next_line(fd);
	split_tab = ft_split(line, ' ');
	if (line)
		i += ft_size_map(split_tab);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		split_tab = ft_split(line, ' ');
		if (line)
			i += ft_size_map(split_tab);
		free(line);
	}
	map = ft_calloc(i , sizeof(t_pixel));
	if (!map)
		return (0);
	return (map);
}

static void	creat_map(t_pixel *map, char **split_tab, int y)
{
	double	x;
	int		i;

	x = 0;
	i = 0;
	while (split_tab[i])
	{
		map->x = x;
		map->y = y;
		map->z = (double)ft_atoi(split_tab[i]);
		map->color = 0x00FFFFFF;
		map->exit = 1;
		printf("%f\n",map->x);
		map++;
		x++;
		i++;
	}
	map->exit = 1;
}

t_pixel	*ft_parcing(char *mapargv)
{
	int		fd;
	char	*line;
	char	**split_tab;
	t_pixel	*map;
	t_pixel *tmp;
	double		y;

	y = 0;
	fd = open(mapargv, O_RDONLY);
	map = ft_malloc_map(fd);
	tmp = map;
	close(fd);
	fd = open(mapargv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		split_tab = ft_split(line, ' ');
		creat_map(&map, split_tab, y);
		line = get_next_line(fd);
		y++;
	}
	return (tmp);
}
