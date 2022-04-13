/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:03:08 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/10 16:30:03 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int s;

	i = 1;
	s = 1;
	if (power >= 0)
	{
		while (i <= power)
		{
			s = nb * s;
			i++;
		}
		return (s);
	}
	else
		return (0);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb > 1073741824)
		return (0);
	if (nb >= 0)
	{
		while (i <= nb)
		{
			if (nb == ft_iterative_power(i, 2))
				return (i);
			i++;
		}
	}
	return (0);
}
