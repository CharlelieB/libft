/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:01:23 by cbessonn          #+#    #+#             */
/*   Updated: 2023/04/10 11:31:44 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_array_free(t_str_array *array)
{
	int	i;

	i = 0;
	if (array->size > 0)
	{
		while (i < array->size)
		{
			free(array->ptr[i]);
			i++;
		}
	}
	free(array->ptr);
}
