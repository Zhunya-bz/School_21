/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:55:02 by saltmer           #+#    #+#             */
/*   Updated: 2021/04/22 11:23:49 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count1;

	i = 0;
	count1 = -1;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] != set[j])
				j++;
			else
				break ;
		}
		if (j == ft_strlen((char *)set))
		{
			count1 = i;
			break ;
		}
		i++;
	}
	return (count1);
}

static int	second(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count2;

	i = 0;
	count2 = -1;
	while (s1[i + 1])
		i++;
	while (i > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] != set[j])
				j++;
			else
				break ;
		}
		if (j == ft_strlen((char *)set))
			break ;
		i--;
	}
	count2 = i;
	return (count2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		count1;
	int		count2;
	char	*strim;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	count1 = first(s1, set);
	count2 = second(s1, set);
	strim = ft_calloc((count2 - count1 + 2), sizeof(char));
	if (strim == NULL)
		return (NULL);
	while ((i + count1 <= count2) && (count1 != -1) && (count2 != -1))
	{
		strim[i] = s1[count1 + i];
		i++;
	}
	strim[i] = '\0';
	return (strim);
}
