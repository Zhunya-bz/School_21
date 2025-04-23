/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:26:56 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/23 16:48:48 by ekanaeva         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	while (i <= 2147483647)
	{
		if (ft_is_prime(i) == 1)
			return (i);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main() {
	printf("after 0:%d\n", ft_find_next_prime(0));
	printf("after -1:%d\n", ft_find_next_prime(-1));
	printf("after 1:%d\n", ft_find_next_prime(1));
	printf("after 5:%d\n", ft_find_next_prime(5));
	printf("after 12:%d\n", ft_find_next_prime(12));
	printf("after max_int:%d\n", ft_find_next_prime(2147483647));
}*/
