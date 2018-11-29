/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_explore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:53:42 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:54:58 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_explore_state	*init_explore_state(void)
{
	t_explore_state		*explore_state;

	if (!(explore_state = (t_explore_state*)malloc(sizeof(t_explore_state))))
		handle_error();
	explore_state->explore = 0;
	explore_state->current = NULL;
	explore_state->placeholder = NULL;
	explore_state->copy = NULL;
	explore_state->replace_index = -1;
	return (explore_state);
}

static void				path_explore_backtrack(t_list *path_current,
						t_node *placeholder)
{
	path_current->node = placeholder;
	path_current->node->next = NULL;
}

void					path_explore(t_layout *layout, t_room *room, int len)
{
	int					i;
	t_explore_state		*state;

	i = 0;
	state = init_explore_state();
	path_explore_preliminary_steps(layout, state, room, len);
	while (state->explore && room->type != END_ROOM && i < room->num_links)
		path_explore(layout, room->links[i++], len + 1);
	if (state->placeholder)
		path_explore_backtrack(layout->path_current, state->placeholder);
	free(state);
}
