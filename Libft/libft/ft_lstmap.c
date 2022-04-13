/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:14:51 by saltmer           #+#    #+#             */
/*   Updated: 2021/04/27 15:42:40 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_el;
	t_list	*head;

	if (!lst)
		return (NULL);
	new_el = ft_lstnew(f(lst->content));
	if (!new_el)
		return (NULL);
	head = new_el;
	while (lst->next)
	{
		lst = lst->next;
		new_el->next = ft_lstnew(f(lst->content));
		if (new_el->next == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new_el = new_el->next;
	}
	return (head);
}
