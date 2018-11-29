/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:33:57 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:34:27 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_list	*init_input_lst(char *input_line, int input_line_len)
{
	t_list *input_lst;

	if (!(input_lst = ft_lstnew((void*)input_line, input_line_len + 1)))
		handle_error();
	return (input_lst);
}

t_list			*input_get(void)
{
	t_list	*input_lst;
	char	*input_line;
	int		input_line_len;

	input_lst = NULL;
	while (get_next_line(0, &input_line))
	{
		input_line_len = ft_strlen(input_line);
		if (!input_lst)
			input_lst = init_input_lst(input_line, input_line_len);
		else
		{
			if (!(input_lst->node->next =
				ft_nodenew((void*)input_line, input_line_len + 1)))
			{
				list_free(input_lst);
				handle_error();
			}
			input_lst->node = input_lst->node->next;
		}
	}
	input_lst->node = input_lst->head;
	return (input_lst);
}
