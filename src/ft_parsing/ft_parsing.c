/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:31:27 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/21 15:59:09 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	ft_size_map(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] == ' ')
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
	line = gc_get_next_line(&w->track, fd);
	if (line)
		w->y_max += 1;
	i = ft_size_map(line);
	w->x_max = i;
	while (line)
	{
		line = gc_get_next_line(&w->track, fd);
		if (line)
			w->y_max += 1;
	}
	i *= w->y_max;
	map = gc_calloc(i + 1, sizeof(t_pixel), &w->track);
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

t_pixel	*creat_map(t_win *w, char **split_tab, int y)
{
	double	x;
	int		i;
	t_pixel	*tmp;
	int		x_max;
	int		y_max;

	x_max = w->x_max / 2;
	y_max = w->y_max / 2;
	x = 0;
	i = 0;
	tmp = w->map;
	while (split_tab[i])
	{
		w->map->z = (double)ft_atoi(split_tab[i]);
		w->map->x = x - (double)x_max;
		w->map->y = y - (double)y_max;
		w->map->z_originel = w->map->z;
		w->map++;
		x++;
		i++;
	}
	return (w->map);
}

t_pixel	*ft_parsing(t_win *w)
{
	int		fd;
	t_pars	p;
	t_pixel	*tmp;
	double	y;

	y = 0;
	w->draw_point = 1;
	fd = open(w->name, O_RDONLY);
	w->map = ft_malloc_map(fd, w);
	tmp = w->map;
	close(fd);
	fd = open(w->name, O_RDONLY);
	p.line = gc_get_next_line(&w->track, fd);
	while (p.line)
	{
		p.line2 = gc_strtrim(&w->track, p.line, "\n");
		p.split_tab = gc_split(&w->track, p.line2, ' ');
		w->map = creat_map(w, p.split_tab, y);
		p.line = gc_get_next_line(&w->track, fd);
		y++;
	}
	ft_color(tmp, w);
	return (tmp);
}
