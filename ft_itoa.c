/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <cbessonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:28:45 by cbessonn          #+#    #+#             */
/*   Updated: 2022/11/15 19:55:19 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nb_len(unsigned int nb)
{
	int	i;

	i = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	int_to_s(unsigned int nb, char *str, unsigned int i)
{
	str[i] = 0;
	i--;
	if (nb)
	{
		while (nb)
		{
			str[i] = (nb % 10) + '0';
			nb /= 10;
			i--;
		}
	}
	else
		str[i] = '0';
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	unsigned int	len;

	nb = (unsigned int)n;
	len = 0;
	if (n < 0)
	{
		nb *= -1;
		len++;
	}
	len += nb_len(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	int_to_s(nb, str, len);
	if (n < 0)
		str[0] = '-';
	return (str);
}
