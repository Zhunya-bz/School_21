/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:33:41 by saltmer           #+#    #+#             */
/*   Updated: 2021/04/19 16:40:32 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen((char *)s);
	while (i < size + 1)
	{
		if (*s == (char)c)
			return ((char *)s);
		i++;
		s++;
	}
	return (NULL);
}
