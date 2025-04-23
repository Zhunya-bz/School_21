/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:11:06 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/22 17:52:27 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	cicle(int nb, char *arr)
{
	int	mod;
	int	i;

	i = 0;
	while (nb != 0)
	{
		mod = nb % 10;
		nb = nb / 10;
		arr[i] = mod + '0';
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	char	arr[12];
	int		i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		nb = -nb;
		i = cicle(nb, arr);
		arr[i] = '-';
	}
	else
	{
		i = cicle(nb, arr);
		i--;
	}
	while (i >= 0)
		write(1, &arr[i--], 1);
}

/*
int	main()
{
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(-2);
	write(1, "\n", 1);
	ft_putnbr(21);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(-2147483647);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
}*/
