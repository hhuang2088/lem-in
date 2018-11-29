/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:46:29 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:46:35 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	room_is_not_redundant(t_list *path_current, char *room_name)
{
	int		count;

	count = 0;
	path_current->node = path_current->head;
	while (path_current->node->next)
	{
		if (!ft_strcmp((char*)path_current->node->content, room_name))
			++count;
		path_current->node = path_current->node->next;
	}
	if (!count)
		return (TRUE);
	return (FALSE);
}
