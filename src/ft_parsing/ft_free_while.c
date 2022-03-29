/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_while.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 03:08:15 by pat               #+#    #+#             */
/*   Updated: 2022/03/28 23:42:15 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_free_while(t_win *w, t_pars *p)
{
	gc_free_malloc(&w->track, (void **)&p->line2);
	gc_free_malloc_split(&w->track, (void ***)&p->split_tab);
	gc_free_malloc(&w->track, (void **)&p->line);
}
