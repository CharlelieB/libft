/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:04:41 by cbessonn          #+#    #+#             */
/*   Updated: 2023/02/15 15:05:04 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int x, unsigned int y)
{
	int	temp;

	if (y == 0)
		return (1);
	temp = ft_power(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
		return (x * temp * temp);
}
