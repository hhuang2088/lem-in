/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:39:38 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:42:37 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			paths_is_true(t_path **paths)
{
	if (paths)
		return (TRUE);
	else
		return (FALSE);
}

int					path_compare(t_layout *layout, char *room, int index)
{
	int		i;
	int		j;

	if (paths_is_true(layout->paths))
	{
		i = 0;
		while (i < layout->num_paths)
		{
			if (layout->paths[i]->room_names)
			{
				j = 0;
				while (layout->paths[i]->room_names[j])
				{
					if (!ft_strcmp(room, layout->paths[i]->room_names[j]) &&
						(index - 1) < j)
						return (i);
					++j;
				}
			}
			++i;
		}
	}
	return (ERROR_CODE);
}

static int			path_free_rooms_in_path(t_path *path, void *path_current)
{
	int		i;

	i = 0;
	while (ft_strcmp(path->room_names[i], (char*)path_current) != 0)
	{
		free(path->room_names[i]);
		++i;
	}
	free(path->room_names[i]);
	return (i);
}

void				path_replace(t_layout *layout, int path_index,
								int new_index)
{
	char	**new_path;
	int		i;
	int		j;

	i = path_free_rooms_in_path(layout->paths[path_index],
		layout->path_current->node->content);
	j = i;
	while (layout->paths[path_index]->room_names[j])
		++j;
	new_path = (char**)malloc(sizeof(char*) * (j - i + new_index + 1));
	j = 0;
	layout->path_current->node = layout->path_current->head;
	while (j < new_index)
	{
		new_path[j++] = ft_strdup((char*)layout->path_current->node->content);
		layout->path_current->node = layout->path_current->node->next;
	}
	while (layout->paths[path_index]->room_names[i])
		new_path[j++] = layout->paths[path_index]->room_names[++i];
	new_path[j] = NULL;
	free(layout->paths[path_index]->room_names);
	layout->paths[path_index]->room_names = new_path;
	layout->paths[path_index]->len = j - 1;
}
