/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:05:27 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/16 22:40:21 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	int i;
	int count1;
	int count2;

	i = 0;
	count1 = 0;
	count2 = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			count1++;
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			count2++;
		i++;
	}
	if ((count1 == length - 1) || (count2 == length - 1))
		return (1);
	else
		return (0);
}
