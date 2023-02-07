/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:11:51 by cbessonn          #+#    #+#             */
/*   Updated: 2022/11/22 16:24:12 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	if ((!dest && !src) || !n)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			*((char *)dest + (i - 1)) = *((char *)src + (i - 1));
			i--;
		}
	}
	return (dest);
}
