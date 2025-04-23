/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:54:24 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/29 16:36:23 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par && par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
/*
int main()
{
	int i = 0;
	char *str[5] = {"ok", "now", "lets do this", " po", "care"};
	struct s_stock_str *arr;
	arr = ft_strs_to_tab(5, str);
	ft_show_tab(arr);
	while (i < 5)
	{
		free(arr[i].copy);
		i++;
	}
	free(arr);
}*/
