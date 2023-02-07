/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:43:41 by cbessonn          #+#    #+#             */
/*   Updated: 2022/11/22 18:12:59 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*cp;
	size_t		i;
	size_t		from;

	if (!s)
		return (0);
	from = start;
	i = 0;
	if (len == 0 || from >= ft_strlen(s))
	{
		cp = malloc(1);
		if (cp == 0)
			return (0);
		*cp = 0;
		return (cp);
	}
	while (s[from++] && i < len)
		i++;
	cp = malloc((i + 1) * sizeof(*s));
	if (cp == 0)
		return (0);
	while (start--)
		s++;
	ft_strlcpy(cp, s, i + 1);
	return (cp);
}
