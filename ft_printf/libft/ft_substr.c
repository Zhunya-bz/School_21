/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:09:06 by saltmer           #+#    #+#             */
/*   Updated: 2021/04/23 14:21:17 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*subs;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	subs = ft_calloc((len + 1), sizeof(char));
	if (subs == NULL)
		return (NULL);
	while (s[i] && (i != start))
		i++;
	while ((s[i]) && (j < len))
	{
		subs[j] = s[i];
		i++;
		j++;
	}
	subs[j] = '\0';
	return (subs);
}
