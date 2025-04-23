/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:54:08 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/23 14:27:56 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		if (i >= 46340)
			return (0);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()  {
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(-1));
	printf("%d\n", ft_sqrt(-25));
	printf("%d\n", ft_sqrt(2147483646));
	printf("max:%d\n", ft_sqrt(2147483647));
}*/
