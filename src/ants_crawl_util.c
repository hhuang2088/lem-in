/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_crawl_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:09:37 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:10:49 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		path_shortest_is_available(t_layout *layout, int ants_queue,
				int path_i)
{
	if (layout->paths[path_i]->len == layout->paths_shortest_len &&
	ants_queue < layout->num_ants && ants_queue < layout->num_ants)
		return (1);
	return (0);
}

static int		path_is_worth_taking(t_layout *layout, int ants_queue,
				int path_i)
{
	if (ants_queue + layout->paths[path_i]->len <=
			layout->num_ants - 1 + layout->paths_shortest_len &&
			ants_queue < layout->num_ants)
		return (1);
	return (0);
}

int				ants_assign_path_and_get_queue(t_layout *layout, int ants_queue)
{
	int		path_i;

	path_i = 0;
	while (path_i < layout->num_paths && ants_queue < layout->num_ants)
	{
		if (path_shortest_is_available(layout, ants_queue, path_i) ||
				path_is_worth_taking(layout, ants_queue, path_i))
		{
			layout->ants[ants_queue]->path = layout->paths[path_i++];
			layout->ants[ants_queue]->phase = ANT_TRAVELING;
			++ants_queue;
		}
		else
			break ;
	}
	return (ants_queue);
}

void			ants_progress_through_path(t_ant **ants, int ants_queue)
{
	int		i;

	i = 0;
	while (i < ants_queue)
	{
		if (ants[i] && ants[i]->path_i < ants[i]->path->len - 1)
			++ants[i]->path_i;
		++i;
	}
}
