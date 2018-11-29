/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:21:36 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:25:31 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			input_read_num_ants(t_layout *layout, char *line)
{
	layout->num_ants = ft_atoi(line);
	layout->step = SCAN_ROOM_DETAIL_STEP;
}

void				input_scan_for_endpoint(t_layout *layout, t_list *input,
					char *line)
{
	if (line[0] == '#' && layout->step == SCAN_ROOM_DETAIL_STEP)
	{
		if (!ft_strcmp(line, "##start") &&
			is_room_detail((char*)input->node->next->content))
			++layout->start;
		else if (!ft_strcmp(line, "##end") &&
			is_room_detail((char*)input->node->next->content))
			++layout->end;
		else
			return ;
	}
	else
		return ;
}

void				input_get_check_format_step(t_layout *layout, char *line)
{
	if (is_ant_count(line) && layout->step == SCAN_NUMBER_ANTS_STEP)
		input_read_num_ants(layout, line);
	else if (is_link_detail(line) && layout->step == SCAN_ROOM_DETAIL_STEP)
		layout->step = SCAN_ROOM_LINK_STEP;
	else
		return ;
}

void				input_increment_room_or_link(t_layout *layout, char *line)
{
	if (is_room_detail(line) && layout->step == SCAN_ROOM_DETAIL_STEP)
		++layout->num_rooms;
	else if (is_link_detail(line) && layout->step == SCAN_ROOM_LINK_STEP)
		++layout->num_links;
	else
		return ;
}
