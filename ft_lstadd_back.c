/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <cbessonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:44:02 by cbessonn          #+#    #+#             */
/*   Updated: 2022/11/17 15:48:41 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*li;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	li = *lst;
	while (li->next)
		li = (li)->next;
	(li)->next = new;
}
