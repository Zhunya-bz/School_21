/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:53:40 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/10 14:21:11 by saltmer          ###   ########.fr       */
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
