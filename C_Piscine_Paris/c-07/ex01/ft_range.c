/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:05:28 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/27 16:26:17 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	res = malloc(sizeof(int) * (max - min + 1));
	if (res == NULL)
		return (NULL);
	while (min + i < max)
	{
		res[i] = min + i;
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>
int main() {
	int *res;
       	res	= ft_range(4,8);
	for (int i = 0; i < 4; i++) {
		printf("%d ", res[i]);
	}
}*/
