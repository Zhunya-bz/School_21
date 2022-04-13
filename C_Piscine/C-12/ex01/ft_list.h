/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:34:09 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/18 14:54:35 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
t_list		*ft_create_elem(void *data);
typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

#endif
