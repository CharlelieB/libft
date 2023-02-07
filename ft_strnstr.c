/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:40:35 by cbessonn          #+#    #+#             */
/*   Updated: 2022/11/22 17:02:02 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	l_len = ft_strlen(little);
	if (l_len == 0)
		return ((char *)big);
	if (!len)
		return (0);
	if (*big && l_len <= len)
	{
		while (*big && len >= l_len)
		{
			if (ft_strncmp(big, little, l_len) == 0)
				return ((char *)big);
			big++;
			len--;
		}
	}
	return (0);
}
