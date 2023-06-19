/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:52:08 by cbessonn          #+#    #+#             */
/*   Updated: 2023/06/19 13:07:55 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_power(int nb)
{
	int	power;

	power = 1;
	nb = nb / 10;
	while (nb)
	{
		nb /= 10;
		power *= 10;
	}
	return (power);
}

ssize_t	ft_putnbr_fd(int nb, int fd)
{
	char		buffer[12];
	int			res;
	int			power;
	short		i;
	long int	unb;

	unb = nb;
	i = 0;
	if (nb < 0)
	{
		buffer[i++] = '-';
		unb = -unb;
	}
	power = get_power(unb);
	while (power)
	{
		res = unb / power;
		buffer[i++] = 48 + res;
		unb = unb - (res * power);
		power /= 10;
	}
	buffer[i++] = 0;
	return (write(fd, buffer, i));
}
