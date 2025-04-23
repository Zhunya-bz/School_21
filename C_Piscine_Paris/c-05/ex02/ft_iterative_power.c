/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:59:28 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/23 12:49:42 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (i < power)
	{
		res = res * nb;
		i++;
	}
	return (res);
}
/*
#include <stdio.h>
int main() {
	printf("%d\n", ft_iterative_power(0, -1));
	printf("%d\n", ft_iterative_power(0,0));
	printf("%d\n", ft_iterative_power(1,1));
	printf("%d\n", ft_iterative_power(2,3));
	printf("%d\n", ft_iterative_power(3,3));
	printf("%d\n", ft_iterative_power(-1, 3));
	printf("%d\n", ft_iterative_power(-1, 2));
	printf("%d\n", ft_iterative_power(3, 0));
}*/
