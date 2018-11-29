/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_generate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:04:58 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:11:04 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			paths_generate(t_layout *layout)
{
	t_room		*start;
	int			i;

	i = 0;
	start = room_get_start(layout);
	path_explore(layout, start, 1);
	layout->path_current->node = layout->path_current->head;
	paths_sort(layout->paths, layout->num_paths);
	layout->paths_shortest_len = layout->paths[0]->len;
	free(layout->path_current);
}
