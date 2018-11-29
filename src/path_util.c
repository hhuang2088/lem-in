/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:20:29 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:28:09 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_path	**get_new_paths(t_layout *layout, int len)
{
	t_path		**new_paths;
	int			i;

	layout->path_current->node = layout->path_current->head;
	i = 0;
	if (!(new_paths = (t_path**)malloc(sizeof(t_path*) *
						(layout->num_paths + 2))))
		return (FALSE);
	while (i < layout->num_paths)
	{
		new_paths[i] = layout->paths[i];
		++i;
	}
	if (!(new_paths[layout->num_paths] = (t_path*)malloc(sizeof(t_path))))
		return (FALSE);
	new_paths[layout->num_paths + 1] = NULL;
	if (!(new_paths[i]->room_names = (char**)malloc(sizeof(char*) * (len + 1))))
		return (FALSE);
	new_paths[layout->num_paths]->room_names[len] = NULL;
	return (new_paths);
}

static int		copy_rooms_to_new_path(t_path **new_paths, t_layout *layout,
				int len)
{
	int			i;

	i = 0;
	while (layout->path_current->node)
	{
		if (!(new_paths[layout->num_paths]->room_names[i] =
			ft_strdup((char*)layout->path_current->node->content)))
			return (FALSE);
		layout->path_current->node = layout->path_current->node->next;
		++i;
	}
	new_paths[layout->num_paths]->len = len;
	return (TRUE);
}

int				path_append(t_layout *layout, int len)
{
	t_path	**new_paths;

	new_paths = get_new_paths(layout, len);
	if (!(copy_rooms_to_new_path(new_paths, layout, len)))
		return (FALSE);
	free(layout->paths);
	layout->paths = new_paths;
	layout->num_paths += 1;
	return (TRUE);
}
