/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:32:30 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/12 19:16:18 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int c;
	int *arr;

	i = 0;
	if (min >= max)
		arr = NULL;
	else
	{
		c = max - min;
		arr = malloc(sizeof(c) * c);
		if (arr == NULL)
			return (NULL);
		while (min < max)
		{
			arr[i] = min;
			i++;
			min++;
		}
	}
	return (arr);
}
