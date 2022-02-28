/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:31:27 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/28 19:54:04 by rmattheo         ###   ########lyon.fr   */
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
static t_pixel	*ft_malloc_map(int fd, t_win *w)
{
	char	*line;
	t_pixel	*map;
	int		i;

	i = 0;
	w->y_max = 0;
	w->x_max = 0;
	line = get_next_line(fd);
	if (line)
		w->y_max += 1;
	i = ft_size_map(line);
	w->x_max = i;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			w->y_max += 1;

	}
	i *= w->y_max;
	printf("x_max = %i\n", w->x_max);
	printf("y_max = %i\n", w->y_max);
	map = ft_calloc(i, sizeof(t_pixel));
	if (!map)
		return (0);
	return (map);
}

int	ft_strchr_size(const char *s, int c)
{
	int	i;

	i = 0;
	if (s[i])
	{
		while (s[i])
		{
			if (s[i] == (char)c)
				return (i);
			i++;
		}
	}
	return (0);
}
t_pixel	*creat_map(t_pixel *map, char **split_tab, int y, int x_max, int y_max)
{
	double	x;
	int		i;
	int		color;
	int		size;

	x = 0;
	i = 0;
	size = 0;
	color = 0x00FFFFFF;
	while (split_tab[i])
	{
		map->z = (double)ft_atoi(split_tab[i]);
		map->x = x - (double)x_max;
		map->y = y - (double)y_max;
		map->z_originel = map->z;
		map->color = color;
		map++;
		x++;
		i++;
	}
	return (map);
}

t_pixel	*ft_parsing(t_win *w)
{
	int		fd;
	t_pars	p;
	t_pixel	*map;
	t_pixel	*tmp;
	double	y;

	y = 0;
	fd = open(w->name, O_RDONLY);
	map = ft_malloc_map(fd, w);
	tmp = map;
	close(fd);
	fd = open(w->name, O_RDONLY);
	p.line = get_next_line(fd);
	while (p.line)
	{
		p.line2 = ft_split(p.line, '\n');
		p.split_tab = ft_split(*p.line2, ' ');
		map = creat_map(map, p.split_tab, y, w->x_max / 2, w->y_max / 2);
		if (!map)
			return (NULL);
		p.line = get_next_line(fd);
		y++;
	}
	ft_color(tmp, w);
	return (tmp);
}
