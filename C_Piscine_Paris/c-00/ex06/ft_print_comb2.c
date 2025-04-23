/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:52:07 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/15 15:52:09 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>

void	ft_print(char i0, char i1, char j0, char j1)
{
	write(1, &i0, 1);
	write(1, &i1, 1);
	write(1, " ", 1);
	write(1, &j0, 1);
	write(1, &j1, 1);
	if (i0 == '9' && i1 == '8' && j0 == '9' && j1 == '9')
	{
		write(1, "\n", 1);
	}
	else
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	char	i0;
	char	i1;
	char	j0;
	char	j1;

	i0 = '0';
	while (i0 <= '9')
	{
		i1 = i0;
		while (i1 <= '9')
		{
			j0 = '0';
			while (j0 <= '9')
			{
				j1 = i1 + 1;
				while (j1 <= '9')
				{
					ft_print(i0, i1, j0, j1);
					j1++;
				}
				j0++;
			}
			i1++;
		}
		i0++;
	}
}*/

/*
int main(){
	ft_print_comb2();
	return 0;
}*/
