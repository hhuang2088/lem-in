/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:30:07 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:31:33 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			input_process(t_list *input, t_layout *layout)
{
	int			i;
	int			type;

	layout->step = 0;
	i = 0;
	type = 1;
	layout->rooms = (t_room**)malloc(sizeof(t_room*) * (layout->num_rooms + 1));
	layout->ants = (t_ant**)malloc(sizeof(t_ant*) * (layout->num_ants + 1));
	layout->rooms[layout->num_rooms] = NULL;
	layout->ants[layout->num_ants] = NULL;
	input->node = input->node->next;
	input_process_room_details(input, layout);
	input_process_link_details(input, layout);
	ants_initialize(layout);
	list_free(input);
	input->node = input->head;
}
