/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:36:32 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:37:23 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_ant	*ant_get(int num)
{
	t_ant		*ret;

	if (!(ret = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	ret->id = num;
	ret->phase = ANT_WAITING;
	ret->path = NULL;
	ret->path_i = 0;
	return (ret);
}

void			ants_initialize(t_layout *layout)
{
	int		i;
	t_room	*start_room;

	i = 0;
	if (!(start_room = room_get_start(layout)))
	{
		ft_printf("error\n");
		exit(0);
	}
	while (i < layout->num_ants)
	{
		if (!(layout->ants[i] = ant_get(i + 1)))
		{
			ft_printf("error\n");
			exit(0);
		}
		++i;
	}
}

void			ants_print_progress(t_layout *layout, int ants_queue)
{
	int		i;

	i = 0;
	while (i < ants_queue)
	{
		if (layout->ants[i]->phase == ANT_TRAVELING)
			ft_printf("L%d-%s ", layout->ants[i]->id,
					layout->ants[i]->path->room_names[layout->ants[i]->path_i]);
		if (layout->ants[i]->path_i == layout->ants[i]->path->len - 1)
			layout->ants[i]->phase = ANT_FINISHED;
		++i;
	}
	ft_printf("\n");
}

int				ants_finished_crossing(t_ant **ants, int num_ants)
{
	int		i;

	i = 0;
	while (i < num_ants)
	{
		if (ants[i++]->phase != ANT_FINISHED)
			return (FALSE);
	}
	return (TRUE);
}
