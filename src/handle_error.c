/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:37:55 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:38:35 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	handle_error(void)
{
	ft_printf("error\n");
	exit(0);
}

void	input_check_format_error(t_list *input, t_layout *ret)
{
	ft_printf("Invalid input\n");
	list_free(input);
	free(ret);
	exit(0);
}
