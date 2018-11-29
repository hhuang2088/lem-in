/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:56:25 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:58:33 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	room_set_link(t_layout *layout, char *line)
{
	t_room		*room1;
	t_room		*room2;
	char		**name_split;

	name_split = ft_strsplit(line, '-');
	room1 = room_get_by_name(layout, name_split[0]);
	room2 = room_get_by_name(layout, name_split[1]);
	room1->links = room_append(room1->links, room2);
	room2->links = room_append(room2->links, room1);
	++room1->num_links;
	++room2->num_links;
}

void		input_process_link_details(t_list *input, t_layout *layout)
{
	char	*line;
	int		i;

	i = 0;
	while (input->node)
	{
		line = ft_strdup((char*)input->node->content);
		if (i < layout->num_links && layout->step == 1 &&
				!input_is_comment(line))
		{
			room_set_link(layout, line);
			++i;
		}
		input->node = input->node->next;
		free(line);
	}
}

static int	input_get_room_type(char *line, int type)
{
	if (!ft_strcmp(line, "##start"))
		return (0);
	else if (!ft_strcmp(line, "##end"))
		return (2);
	else
		return (type);
}

void		input_process_room_details(t_list *input, t_layout *layout)
{
	int		type;
	int		i;
	char	*line;

	type = 1;
	i = 0;
	while (input->node && layout->step == 0 && i < layout->num_rooms)
	{
		line = ft_strdup((char*)input->node->content);
		if (!input_is_comment(line))
		{
			type = input_get_room_type(line, type);
			if (is_room_detail(line))
			{
				layout->rooms[i++] = room_get(line, type);
				type = 1;
			}
		}
		free(line);
		input->node = input->node->next;
		if (i == layout->num_rooms)
			layout->step = 1;
	}
}
