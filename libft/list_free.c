/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:27:54 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/28 21:39:05 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	node_free(t_node *node)
{
	if (node->next)
		node_free(node->next);
	free(node->content);
	free(node);
}

void	list_free(t_list *list)
{
	if (list->head)
		node_free(list->head);
	free(list);
}
