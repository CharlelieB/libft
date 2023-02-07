/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:45:06 by cbessonn          #+#    #+#             */
/*   Updated: 2022/11/18 12:19:14 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**new_lst;
	t_list	*head;
	t_list	*temp;

	temp = lst;
	head = 0;
	new_lst = &head;
	while (temp)
	{
		if (f)
			*new_lst = ft_lstnew(f(temp->content));
		if (*new_lst == 0)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		new_lst = &(*new_lst)->next;
		temp = temp->next;
	}
	return (head);
}
