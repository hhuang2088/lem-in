/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:11:57 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:18:12 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			paths_sort(t_path **paths, int num_paths)
{
	int		sorted;
	int		i;
	t_path	*tmp;

	sorted = 1;
	while (sorted)
	{
		sorted = 0;
		i = 0;
		while (i + 1 < num_paths)
		{
			if (paths[i + 1]->len < paths[i]->len)
			{
				tmp = paths[i + 1];
				paths[i + 1] = paths[i];
				paths[i] = tmp;
				sorted = 1;
			}
			++i;
		}
	}
}
