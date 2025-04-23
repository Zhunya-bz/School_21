/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:02:49 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/19 17:16:54 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char*src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if ((!dest) || (!src))
		return (0);
	if (size > 0)
	{
		while ((i < size - 1) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
int main() {
	char dest[] = "dest";
	char src[] = "sour";
	printf("%d\n%s\n", ft_strlcpy(dest, src, 3), dest);	
}*/
