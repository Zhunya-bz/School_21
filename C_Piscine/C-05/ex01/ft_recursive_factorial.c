/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:24:22 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/10 14:20:54 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb >= 0)
	{
		if (nb == 0)
			return (1);
		else
			return (ft_recursive_factorial(nb - 1) * nb);
	}
	else
		return (0);
}
