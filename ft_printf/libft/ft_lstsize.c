/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:45:29 by saltmer           #+#    #+#             */
/*   Updated: 2021/04/27 18:10:56 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*copy_lst;

	count = 0;
	copy_lst = lst;
	if (!lst)
		return (0);
	while (copy_lst != NULL)
	{
		count++;
		copy_lst = copy_lst->next;
	}
	return (count);
}
