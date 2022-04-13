/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:49:31 by saltmer           #+#    #+#             */
/*   Updated: 2021/04/25 12:59:20 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*go_to_pointer(const char *big, int i)
{
	int	count;

	count = 0;
	while (count++ < i)
		big++;
	return ((char *)big);
}

static char	*go_to_string(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((i < (int)len) && (big[i]))
	{
		j = 0;
		while ((big[i + j] == little[j]) && (i + j < (int)len))
		{
			j++;
			if (j == ft_strlen((char *)little))
				return (go_to_pointer((char *)big, i));
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen((char *)little) > ft_strlen((char *)big))
		return (NULL);
	if (little[j] == '\0')
		return (((char *) big));
	return (go_to_string(big, little, len));
}
