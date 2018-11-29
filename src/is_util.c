/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:43:21 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 16:44:08 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			is_link_detail(char *line)
{
	int		i;
	int		dash_count;
	int		nl_count;
	int		len;

	i = 0;
	nl_count = 0;
	dash_count = 0;
	len = ft_strlen(line);
	if (len < 3)
		return (0);
	while (line[i])
	{
		if (line[i] == '-')
			++dash_count;
		if (line[i] == ' ' || line[i] == '\t' ||
			(line[i] == '\n' && i != len - 1))
			return (0);
		++i;
	}
	if (dash_count != 1)
		return (0);
	return (1);
}

int			is_room_detail(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(line);
	if (len < 5)
		return (0);
	if (line[i] && !ft_isprint(line[i]) && (line[0] == '#' || line[0] == 'L'))
		return (0);
	while (line[i] && !ft_iswhitespace(line[i]))
		++i;
	if (ft_iswhitespace(line[i]) && line[i + 1])
		++i;
	if (!ft_isdigit(line[i]))
		return (0);
	while (line[i] && ft_isdigit(line[i]))
		++i;
	if (line[i] && ft_iswhitespace(line[i]) && line[i + 1])
		++i;
	if (line[i] && !ft_isdigit(line[i]))
		return (0);
	return (1);
}

int			is_ant_count(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(line);
	if (len < 1)
		return (0);
	while (i < len)
	{
		if (!ft_isdigit(line[i]))
			return (0);
		++i;
	}
	return (1);
}

int			input_is_comment(char *line)
{
	if (line[0] == '#' &&
		ft_strcmp("##start", line) != 0 &&
		ft_strcmp("##end", line) != 0)
		return (1);
	else
		return (0);
}
