/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:53:01 by cbessonn          #+#    #+#             */
/*   Updated: 2022/11/22 17:06:14 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, const char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		len;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	while (s1[len - 1] && is_sep(s1[len - 1], set))
		len--;
	while (*s1 && is_sep(*s1, set) && len > 0)
	{
		s1++;
		len--;
	}
	str = malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	i = 0;
	while (len--)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
