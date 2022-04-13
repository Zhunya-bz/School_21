/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:19:21 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/04 20:15:39 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	 print(i, j, k)
{
	char z;
	char s;

	z = ',';
	s = 32;
	if ((i == '7') && (i < j) && (j < k))
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
	}
	else if ((i < j) && (j < k) && (i != j) && (j != k))
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
		write(1, &z, 1);
		write(1, &s, 1);
	}
}

void	ft_print_comb(void)
{
	char i;
	char j;
	char k;

	i = '0';
	while (i <= '7')
	{
		j = '1';
		while (j <= '9')
		{
			k = '2';
			while (k <= '9')
			{
				print(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
