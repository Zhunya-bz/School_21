/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:50:15 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/23 13:48:00 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <stdio.h>
int main() {
	printf("%d\n", ft_recursive_power(0,0));
	printf("%d\n", ft_recursive_power(1,3));
	printf("%d\n", ft_recursive_power(-1,0));
	printf("%d\n", ft_recursive_power(0,-1));
	printf("%d\n", ft_recursive_power(2,3));
	printf("%d\n", ft_recursive_power(-1,3));
	printf("%d\n", ft_recursive_power(-1,2));
	printf("%d\n", ft_recursive_power(2,4));
}*/
