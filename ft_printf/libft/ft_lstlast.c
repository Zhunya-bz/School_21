/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:53:00 by saltmer           #+#    #+#             */
/*   Updated: 2021/04/27 13:56:00 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*copy_lst;

	copy_lst = lst;
	if (!lst)
		return (0);
	while (copy_lst->next != NULL)
	{
		copy_lst = copy_lst->next;
	}
	return (copy_lst);
}
