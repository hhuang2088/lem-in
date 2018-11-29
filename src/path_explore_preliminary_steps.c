/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_explore_preliminary_steps.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:13:14 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:19:13 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		set_initial_path_current(t_layout *layout,
				t_explore_state *state)
{
	if (!(layout->path_current =
		ft_lstnew((void*)state->copy, ft_strlen(state->copy) + 1)))
		handle_error();
	state->explore = TRUE;
	state->current = layout->path_current->node;
	state->placeholder = layout->path_current->node;
}

static	void	set_new_room_to_path(t_layout *layout,
				t_explore_state *state)
{
	if (!(layout->path_current->node->next =
				ft_nodenew((void*)state->copy,
				ft_strlen(state->copy) + 1)))
		handle_error();
	state->placeholder = layout->path_current->node;
	layout->path_current->node = layout->path_current->node->next;
	state->explore = TRUE;
	state->current = layout->path_current->node;
}

static void		path_compare_and_replace(t_layout *layout,
				t_explore_state *state, t_room *room, int len)
{
	state->replace_index = path_compare(layout, room->name, len);
	if (state->replace_index > NON_INDEX)
	{
		path_replace(layout, state->replace_index, len);
		state->explore = FALSE;
	}
}

void			path_explore_preliminary_steps(t_layout *layout,
				t_explore_state *state, t_room *room, int len)
{
	if (!(state->copy = ft_strdup(room->name)))
		handle_error();
	if (!layout->path_current)
		set_initial_path_current(layout, state);
	else if (room_is_not_redundant(layout->path_current, room->name))
		set_new_room_to_path(layout, state);
	if (room->type == MID_ROOM)
		path_compare_and_replace(layout, state, room, len);
	if (room->type == END_ROOM && !(path_append(layout, len)))
		handle_error();
	layout->path_current->node = state->current;
}
