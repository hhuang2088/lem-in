/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:32:16 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:32:22 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_layout			*input_check_format(t_list *input)
{
	t_layout		*ret;
	char			*line;
	int				len;

	ret = layout_init();
	while (input->node)
	{
		line = ft_strdup((char*)input->node->content);
		len = ft_strlen(line);
		input_get_check_format_step(ret, line);
		if (!ft_strlen(line) && ret->step != SCAN_ROOM_LINK_STEP)
			input_check_format_error(input, ret);
		input_increment_room_or_link(ret, line);
		input_scan_for_endpoint(ret, input, line);
		input->node = input->node->next;
		free(line);
	}
	if (ret->start != TRUE || ret->end != TRUE ||
		ret->step != SCAN_ROOM_LINK_STEP)
		input_check_format_error(input, ret);
	input->node = input->head;
	return (ret);
}
