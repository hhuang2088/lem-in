/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:51:28 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:51:51 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*room_get_start(t_layout *layout)
{
	int		i;

	i = 0;
	while (i < layout->num_rooms)
	{
		if (layout->rooms[i]->type == START_ROOM)
			return (layout->rooms[i]);
		++i;
	}
	return (NULL);
}

t_room		**room_append(t_room **room_ptr, t_room *room)
{
	int		i;
	int		len;
	t_room	**ret;

	i = 0;
	len = 0;
	if (room_ptr)
	{
		while (room_ptr[len])
			++len;
	}
	ret = (t_room**)malloc(sizeof(t_room*) * (len + 2));
	ret[len + 1] = NULL;
	while (i < len)
	{
		ret[i] = room_ptr[i];
		++i;
	}
	ret[i] = room;
	if (len > 0)
		free(room_ptr);
	return (ret);
}

t_room		*room_get_by_name(t_layout *layout, char *name)
{
	int		i;

	i = 0;
	while (i < layout->num_rooms)
	{
		if (ft_strcmp(layout->rooms[i]->name, name) == 0)
			return (layout->rooms[i]);
		++i;
	}
	return (NULL);
}

t_room		*room_get(char *input, int type)
{
	char	**inp_split;
	int		i;
	t_room	*ret;

	i = 0;
	if (!(ret = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (!(inp_split = ft_strsplit(input, ' ')))
		return (NULL);
	ret->name = ft_strdup(inp_split[0]);
	ret->x_cord = ft_atoi(inp_split[1]);
	ret->y_cord = ft_atoi(inp_split[2]);
	ret->links = NULL;
	ret->type = type;
	ret->num_links = 0;
	while (i < 3)
		free(inp_split[i++]);
	free(inp_split);
	return (ret);
}
