/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <cbessonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:14:13 by cbessonn          #+#    #+#             */
/*   Updated: 2023/10/16 17:28:50 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	line_allocate(char **line, int *malloc_size)
{
	char	*str;
	int		i;

	i = 0;
	*malloc_size = ft_next_power(*malloc_size);
	str = malloc(*malloc_size);
	if (!str)
	{
		if (*line)
			free(*line);
		return (false);
	}
	if (*line)
	{
		while ((*line)[i])
		{
			str[i] = (*line)[i];
			i++;
		}
		free(*line);
	}
	str[i] = 0;
	*line = str;
	return (true);
}

void	line_edit(char **line, char *buffer, int *line_size)
{
	int	i;

	i = 0;
	while ((*line)[i])
		i++;
	while (*buffer && *buffer != '\n')
		(*line)[i++] = *buffer++;
	if (*buffer == '\n')
		(*line)[i++] = '\n';
	(*line)[i] = 0;
	*line_size = i;
}

char	*line_resize(char **line)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen(*line) + 1);
	if (str == 0)
		return (0);
	while ((*line)[i])
	{
		str[i] = (*line)[i];
		i++;
	}
	str[i] = 0;
	free(*line);
	return (str);
}
