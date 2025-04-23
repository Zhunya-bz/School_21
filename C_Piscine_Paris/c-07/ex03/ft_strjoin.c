/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:45:55 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/28 12:23:09 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_len_str(char **strs, int size, char *sep)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < size - 1)
	{
		res += ft_len(strs[i]) + ft_len(sep);
		i++;
	}
	res += ft_len(strs[i]);
	return (res);
}

char	*ft_strcat(char *dest, char *src)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		lens;
	int		i;

	i = 0;
	if (size == 0)
	{
		res = malloc(sizeof(char));
		*res = '\0';
		return (res);
	}
	lens = ft_len_str(strs, size, sep);
	res = malloc(sizeof(char) * (lens + 1));
	if (res == NULL)
		return (NULL);
	while (i < size - 1)
	{
		res = ft_strcat(res, strs[i]);
		res = ft_strcat(res, sep);
		i++;
	}
	res = ft_strcat(res, strs[i]);
	return (res);
}
/*
#include <stdio.h>
int main() {
	char **strs;
	strs = malloc(sizeof(char *) * 6);
	for (int i = 0; i < 6; i++) {
		strs[i] = malloc(sizeof(char) * 6);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			strs[i][j] = 'a' + i;
		}
	}
	char sep[]="-+";
	printf("%s\n", ft_strjoin(5, strs, sep));
}*/