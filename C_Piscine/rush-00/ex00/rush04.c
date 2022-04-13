/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:37:11 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/07 16:55:39 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_line(int i, int x)
{
	ft_putchar('A');
	i++;
	if (i == x)
		ft_putchar('\n');
	while (i < x)
	{
		if (i == x - 1)
		{
			ft_putchar('C');
			ft_putchar('\n');
		}
		else
			ft_putchar('B');
		i++;
	}
}

void	second_line(int i, int x)
{
	i = 1;
	ft_putchar('B');
	if (i == x)
		ft_putchar('\n');
	while (i < x)
	{
		if (i == x - 1)
		{
			ft_putchar('B');
			ft_putchar('\n');
		}
		else
			ft_putchar(32);
		i++;
	}
}

void	last_line(int i, int x)
{
	i = 1;
	ft_putchar('C');
	if (i == x)
		ft_putchar('\n');
	while (i < x)
	{
		if (i == x - 1)
		{
			ft_putchar('A');
			ft_putchar('\n');
		}
		else
			ft_putchar('B');
		i++;
	}
}

void	rush04(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	first_line(i, x);
	j++;
	while (j < y - 1)
	{
		second_line(i, x);
		j++;
	}
	if (j == y - 1)
		last_line(i, x);
}
