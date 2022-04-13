/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:34:41 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/10 14:21:36 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power >= 0)
	{
		if (power == 0)
			return (1);
		else
			return (ft_recursive_power(nb, power - 1) * nb);
	}
	else
		return (0);
}
