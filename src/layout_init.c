/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:23:51 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:26:35 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_layout			*layout_init(void)
{
	t_layout		*ret;

	ret = (t_layout*)malloc(sizeof(t_layout));
	ret->num_ants = 0;
	ret->num_rooms = 0;
	ret->num_links = 0;
	ret->num_paths = 0;
	ret->paths_shortest_len = INT_MAX;
	ret->rooms = NULL;
	ret->ants = NULL;
	ret->paths = NULL;
	ret->path_current = NULL;
	ret->step = 0;
	ret->start = 0;
	ret->end = 0;
	return (ret);
}
