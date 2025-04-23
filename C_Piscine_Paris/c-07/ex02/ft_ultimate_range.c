/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:28:00 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/27 16:39:55 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*res;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (max - min > 2147483647 || max - min < -2147483648)
		return (-1);
	res = malloc(sizeof(int) * (max - min + 1));
	if (res == NULL)
		return (-1);
	while (i < max - min)
	{
		res[i] = min + i;
		i++;
	}
	*range = res;
	return (i);
}
/*
#include <stdio.h>
int main() {
	int **s;
	int *tab;
	s = &tab;
	printf("%d\n", ft_ultimate_range(s, 4,8));
	for(int i = 0; i< 12;i++)
		printf("%d ",tab[i]);
}*/