/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:39:15 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/17 15:40:20 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft.h"

int	ft_atoi(char *str)
{
	unsigned	int	i;
	unsigned	int	sign;
	int				res;

	i = 0;
	sign = 0;
	res = 0;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (int)str[i] - '0';
		i++;
	}
	if (sign % 2 != 0)
		return (-res);
	else
		return (res);
}
//#include <stdio.h>
//int main()
//{
//	char str[5]="toto3";
//	printf("%d", ft_atoi(str));
//}
