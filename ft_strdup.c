/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:44:56 by cbessonn          #+#    #+#             */
/*   Updated: 2022/11/18 13:16:35 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		n;
	char		*cp;

	n = ft_strlen(s) + 1;
	cp = malloc(n * sizeof(char));
	if (cp == 0)
		return (0);
	ft_strlcpy(cp, s, n);
	return (cp);
}
