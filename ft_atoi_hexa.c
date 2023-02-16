/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:42:44 by cbessonn          #+#    #+#             */
/*   Updated: 2023/02/16 13:42:47 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	nb_is_correct(const char *nb, const char *base, int base_len)
{
	while (*nb)
	{
		if (!ft_memchr(base, *nb, base_len))
			return (false);
		nb++;
	}
	return (true);
}

bool	base_is_correct(const char *base, int base_len)
{
	while (*(base))
	{
		if (!ft_isalnum(*base))
			return (false);
		if (*(base + 1))
			if (ft_memchr(base + 1, *base, base_len))
				return (false);
		base_len--;
		base++;
	}
	return (true);
}

bool	parsing(const char *nb, const char *base, int base_len)
{
	if (!base || !nb)
		return (false);
	if (!nb_is_correct(nb, base, base_len))
		return (false);
	return (true);
}

int	get_index(char c, const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			break ;
		i++;
	}
	return (i);
}

int	ft_atoi_hexa(const char *nptr)
{
	int		nb;
	int		base_len;
	size_t	nb_len;
	char	*base;

	base = "0123456789abcdef";
	if (!str_is_lower(nptr))
		base = "0123456789ABCDEF";
	base_len = 16;
	if (!parsing(nptr, base, 16))
		return (0);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	nb = 0;
	nb_len = ft_strlen(nptr);
	while (*nptr)
	{
		nb += get_index(*nptr, base) * ft_power(base_len, nb_len - 1);
		nptr++;
		nb_len--;
	}
	return (nb);
}
