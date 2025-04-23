/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:24:50 by rnunes            #+#    #+#             */
/*   Updated: 2025/01/18 15:41:04 by rnunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_first(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == x - 1)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
		i++;
	}
	ft_putchar('\n');
}

void	print_middle(int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < y - 2)
	{
		i = 0;
		while (i < x)
		{
			if (i == 0 || i == x - 1)
			{
				ft_putchar('|');
			}
			else
			{
				ft_putchar(' ');
			}
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

void	print_last(int x, int y)
{
	int	i;

	i = 0;
	while (i < x && y > 1)
	{
		if (i == 0 || i == x - 1)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
		i++;
	}
	if (y > 1)
		ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		print_first(x);
		print_middle(x, y);
		print_last(x, y);
	}
}
