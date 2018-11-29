/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:29:18 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:29:20 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				main(void)
{
	t_list		*input;
	t_layout	*layout;

	if (!(input = input_get()))
		return (0);
	if (!(layout = input_check_format(input)))
		return (0);
	input_process(input, layout);
	paths_generate(layout);
	ants_crawl(layout);
	free(layout);
	return (0);
}
