/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:01:58 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/02/04 14:25:46 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			p = i;
			j = 0;
			while (str[i] && to_find[j] && str[i] == to_find[j])
			{
				i++;
				j++;
			}
			if (to_find[j] == '\0')
				return (p);
			i = p;
		}
		i++;
	}
	return (0);
}

char	*ft_move(char *s, char *charset, int amount)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	while (charset[j])
		j++;
	while (s && k < j + amount)
	{
		s++;
		k++;
	}
	return (s);
}

char	**fill(char **res, int j, char **str2, char *charset)
{
	int	i;
	int	sep_idx;

	i = 0;
	sep_idx = ft_strstr(*str2, charset);
	res[j] = malloc(sizeof(char) * (sep_idx + 1));
	while (i < sep_idx)
	{
		res[j][i] = (*str2)[i];
		i++;
	}
	*str2 = ft_move(*str2, charset, sep_idx);
	return (res);
}

int	count_words(char *str, char *charset)
{
	char	*tmp;
	int		i;
	int		p;
	int		k;
	int		j;

	i = 0;
	tmp = str;
	j = 0;
	while (charset[j])
		j++;
	while (ft_strstr(tmp, charset))
	{
		p = ft_strstr(tmp, charset);
		i++;
		k = 0;
		while (tmp && k < j + p)
		{
			tmp++;
			k++;
		}
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	char	*str2;
	int		i;
	int		len;

	len = count_words(str, charset);
	res = malloc(sizeof(char *) * (len + 2));
	str2 = str;
	i = 0;
	while (*str2)
	{
		if (ft_strstr(str2, charset))
			fill(res, i, &str2, charset);
		else if (*str2)
		{
			res[i++] = str2;
			break ;
		}
		i++;
	}
	res[i] = 0;
	return (res);
}
/*
#include <string.h>
#include <stdio.h>
int main() {
	char str[33] = "hello kek 11s11kek3P2PPPPwerkek ";
	char ** res = ft_split(str, "ke");
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", res[i]);
	}
}*/
