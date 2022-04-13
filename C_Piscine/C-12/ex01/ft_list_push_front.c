/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:12:08 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/18 23:00:32 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *newhead;

	newhead = ft_create_elem(data);
	newhead->data = data;
	newhead->next = *begin_list;
	*begin_list = newhead;
}
