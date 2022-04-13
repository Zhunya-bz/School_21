/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:29:24 by saltmer           #+#    #+#             */
/*   Updated: 2021/04/24 11:31:42 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if ((char)s[i] != c)
		{
			len++;
			while ((s[i]) && ((char)s[i] != c))
				i++;
		}
		else
			i++;
	}
	return (len);
}

static void	free_func(char **res, int count)
{
	while (count >= 0)
	{
		free(res[count]);
		count--;
	}
	free(res);
}

static char	**operation(char const *s, char c, char **res, int c_words)
{
	int		start;
	int		end;
	int		count;

	start = 0;
	count = 0;
	while (count < c_words)
	{
		while ((s[start]) && (s[start] == c))
			start++;
		end = start;
		while ((s[end]) && (s[end] != c))
			end++;
		res[count] = ft_substr(s, start, end - start);
		if (res[count] == NULL)
		{
			free_func(res, count);
			return (NULL);
		}
		start = end;
		count++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		c_words;

	if (!s)
		return (NULL);
	c_words = count_words(s, c);
	res = (char **)ft_calloc((c_words + 1), sizeof(char *));
	if (!res)
		return (NULL);
	res = operation(s, c, res, c_words);
	return (res);
}
