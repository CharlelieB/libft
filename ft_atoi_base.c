/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:00:32 by cbessonn          #+#    #+#             */
/*   Updated: 2023/02/15 15:10:41 by cbessonn         ###   ########.fr       */
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

bool	parsing(const char *nb, const char *base, int *base_len)
{
	if (!base || !nb)
		return (false);
	*base_len = ft_strlen(base);
	if (*base_len <= 1)
		return (false);
	if (!base_is_correct(base, *base_len))
		return (false);
	if (!nb_is_correct(nb, base, *base_len))
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

int	ft_atoi_base(const char *nptr, const char *base)
{
	int		nb;
	int		base_len;
	size_t	nb_len;

	base_len = 0;
	if (!parsing(nptr, base, &base_len))
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
