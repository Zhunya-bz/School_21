/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:10:51 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/09 15:29:32 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put(int i, int nb, char a, char *arr)
{
	if (nb < 0)
	{
		while (nb != 0)
		{
			a = (nb % 10) * (-1) + '0';
			nb = nb / 10;
			arr[i] = a;
			i++;
		}
		arr[i] = '-';
		arr[i + 1] = '\0';
	}
	else
	{
		while (nb != 0)
		{
			a = nb % 10 + '0';
			nb = nb / 10;
			arr[i] = a;
			i++;
		}
		i--;
	}
}

void	ft_putnbr(int nb)
{
	char	a;
	char	arr[12];
	int		i;

	i = 0;
	put(i, nb, a, arr);
	while (arr[i] != '\0')
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &arr[i], 1);
		i--;
	}
}
