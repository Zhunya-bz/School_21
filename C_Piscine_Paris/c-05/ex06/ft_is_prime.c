/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:48 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/23 16:37:38 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < nb)
	{
		if (nb % i == 0)
			count++;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main(){
	printf("-1:%d\n", ft_is_prime(-1));
	printf("0:%d\n", ft_is_prime(0));
	printf("1:%d\n", ft_is_prime(1));
	printf("2:%d\n", ft_is_prime(2));
	printf("3:%d\n", ft_is_prime(3));
	printf("5:%d\n", ft_is_prime(5));
	printf("7:%d\n", ft_is_prime(7));
	printf("12:%d\n", ft_is_prime(12));
	printf("max_int:%d\n", ft_is_prime(2147483647));
}*/
