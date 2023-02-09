/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <cbessonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:14:02 by cbessonn          #+#    #+#             */
/*   Updated: 2023/02/09 15:59:47 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	buffer_check(char *buffer, int n)
{
	int	i;

	i = 0;
	if (n < BF_SIZE)
		return (true);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

void	buffer_clean(char *buffer, bool line_found)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (line_found)
	{
		while (buffer[i] && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
			i++;
		while (buffer[i])
			buffer[j++] = buffer[i++];
	}
	buffer[j] = 0;
}

bool	buffer_read(char *buffer, int fd, int *n)
{
	if (*buffer == 0)
	{
		*n = read(fd, buffer, BF_SIZE);
		buffer[*n] = 0;
	}
	if (*n <= 0)
		return (false);
	return (true);
}

bool	line_read(char *buffer, int fd, char **line, int *n)
{
	int		malloc_size;
	bool	line_found;
	int		line_size;

	malloc_size = BF_SIZE;
	line_found = false;
	line_size = 0;
	while (!line_found)
	{
		if (!buffer_read(buffer, fd, n))
			return (false);
		line_found = buffer_check(buffer, *n);
		if (malloc_size < line_size + 1 + BF_SIZE)
		{
			if (!line_allocate(line, &malloc_size))
				return (false);
		}
		line_edit(line, buffer, &line_size);
		buffer_clean(buffer, line_found);
	}
	return (true);
}

bool	get_next_line(int fd, char **line)
{
	static char	buffer[BF_SIZE + 1];
	int			n;

	if (fd < 0 || fd > 1023 || BF_SIZE <= 0)
		return (false);
	n = BF_SIZE;
	if (!line_read(buffer, fd, line, &n))
		return (false);
	if (*line)
		*line = line_resize(line);
	return (true);
}
