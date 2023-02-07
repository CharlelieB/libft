/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:16:38 by cbessonn          #+#    #+#             */
/*   Updated: 2022/11/22 15:32:35 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*ptr;
	size_t			n;

	ptr = 0;
	if ((size && (nmemb * size / size) != nmemb))
		return (0);
	n = nmemb * size;
	ptr = malloc(n);
	if (!ptr)
		return (0);
	ft_bzero(ptr, n);
	return (ptr);
}
