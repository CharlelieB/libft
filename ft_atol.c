/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:48:10 by cbessonn          #+#    #+#             */
/*   Updated: 2023/05/09 17:48:20 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atol(const char *nptr)
{
	int			signe;
	long int	nb;

	signe = 1;
	nb = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signe *= -signe;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		nb = 10 * nb + (*nptr - 48);
		nptr++;
	}
	return (nb * signe);
}
