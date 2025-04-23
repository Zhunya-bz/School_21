/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:26:24 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/22 17:49:05 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	unsigned int	i;
	unsigned long	res;
	unsigned int	num;

	i = 0;
	res = 0;
	num = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			num++;
		i++;
	}
	while ((str[i] && str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (num % 2 == 0)
		return (res);
	else
		return (-1 * res);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main() {
	printf("%d\n", ft_atoi("42"));
	printf("atoi:%d\n", atoi("42"));
	printf("%d\n", ft_atoi("     42"));
	printf("atoi:%d\n", atoi("     42"));
	printf("%d\n", ft_atoi("     ---+--+1234ab567"));
	printf("atoi:%d\n", atoi("     ---+--+1234ab567"));
	printf("%d\n", ft_atoi("    -42"));
	printf("atoi:%d\n", atoi("    -42"));
	printf("%d\n", ft_atoi(" --42"));
	printf("atoi:%d\n", atoi(" --42"));
}*/
