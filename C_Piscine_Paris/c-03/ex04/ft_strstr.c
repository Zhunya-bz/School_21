/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:13:38 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/20 13:51:33 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	j = 0;
	while (str[i])
	{
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
				return (&str[p]);
		}
		i++;
	}
	return ("");
}

/*
#include <stdio.h>
int main() {
	char str[] = "sdfsdflolaqaqaaaawasfgew123lola";
	char f[] = "lola";
	printf("%s\n", ft_strstr(str, f));
}*/