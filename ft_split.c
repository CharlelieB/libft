/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <cbessonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:52:10 by cbessonn          #+#    #+#             */
/*   Updated: 2023/02/08 11:23:52 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	return (c == sep);
}

static int	count_words(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s && !is_sep(*s, c))
		{
			size++;
			while (*s && !is_sep(*s, c))
				s++;
		}
	}
	return (size);
}

static char	*str_dup(char const *s, char c)
{
	int		i;
	char	*array;

	i = 0;
	while (s[i] && !is_sep(s[i], c))
		i++;
	array = malloc(sizeof(char) * (i + 1));
	if (array == 0)
		return (0);
	i = 0;
	while (s[i] && !is_sep(s[i], c))
	{
		array[i] = s[i];
		i++;
	}
	array[i] = 0;
	return (array);
}

bool	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free (array);
	return (false);
}

bool	ft_split(t_str_array *array, char const *s, char c)
{
	int		i;

	if (!s)
		return (false);
	i = 0;
	array->ptr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (array->ptr == 0)
		return (false);
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s && !is_sep(*s, c))
		{
			array->ptr[i] = str_dup(s, c);
			if (!array->ptr[i++])
				return (free_array(array->ptr));
			while (*s && !is_sep(*s, c))
				s++;
		}
	}
	array->ptr[i] = 0;
	array->size = i;
	return (true);
}
