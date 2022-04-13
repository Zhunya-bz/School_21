/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:30:54 by saltmer           #+#    #+#             */
/*   Updated: 2021/04/30 16:55:57 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	newstr = (char *)malloc(((ft_strlen((char *)s1)
					+ ft_strlen((char *)s2) + 1)) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;
	size_t	i;

	i = 0;
	cal = (void *)malloc(count * size);
	if (cal == NULL)
		return (NULL);
	while (i < (size * count))
	{
		((unsigned char *)cal)[i] = '\0';
		i++;
	}
	return (cal);
}
