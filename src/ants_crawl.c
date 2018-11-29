/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_crawl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:45:01 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:45:44 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ants_crawl(t_layout *layout)
{
	int		ants_queue;
	int		complete;

	ants_queue = 0;
	complete = 0;
	while (!complete)
	{
		if (ants_queue < layout->num_ants)
			ants_queue = ants_assign_path_and_get_queue(layout, ants_queue);
		ants_progress_through_path(layout->ants, ants_queue);
		ants_print_progress(layout, ants_queue);
		complete = ants_finished_crossing(layout->ants, layout->num_ants);
	}
}
