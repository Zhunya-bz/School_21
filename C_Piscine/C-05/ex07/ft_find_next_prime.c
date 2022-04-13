/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:15:05 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/10 14:22:24 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;
	int s;

	i = 1;
	s = 0;
	if (nb > 1)
	{
		while (i <= nb)
		{
			if ((nb % i) == 0)
				s++;
			i++;
		}
		if (s == 2)
			return (1);
	}
	return (0);
}

int		ft_find_next_prime(int nb)
{
	int i;

	if (nb >= 0)
		i = nb;
	else
		i = 0;
	if (ft_is_prime(i) == 1)
		return (i);
	else
	{
		while (ft_is_prime(i) != 1)
		{
			i++;
		}
		return (i);
	}
}
