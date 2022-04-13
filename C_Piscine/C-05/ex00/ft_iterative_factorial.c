/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:18:02 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/10 14:20:35 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int s;

	i = 1;
	s = 1;
	if (nb >= 0)
	{
		while (i <= nb)
		{
			s = s * i;
			i++;
		}
		return (s);
	}
	else
		return (0);
}
