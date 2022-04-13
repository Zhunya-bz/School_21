/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:36:45 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/12 20:20:27 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int c;
	int *arr;

	i = 0;
	c = max - min;
	if ((c > 2147483647) || (c < -2147483648))
		return (-1);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		arr = malloc(sizeof(c) * c);
		while (min < max)
		{
			arr[i] = min;
			i++;
			min++;
		}
		*range = arr;
	}
	return (c);
}
