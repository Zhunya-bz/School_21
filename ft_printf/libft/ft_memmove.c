/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:06:30 by saltmer           #+#    #+#             */
/*   Updated: 2021/04/20 13:02:57 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	int	i;

	i = -1;
	if ((!dest) && (!src))
		return (NULL);
	if (len > 0)
	{
		if (dest < src)
		{
			while (i++ < (int)len - 1)
				((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
		else if (dest > src)
		{
			while ((int)len - 1 >= 0)
			{
				((unsigned char *)dest)[len - 1]
					 = ((unsigned char *)src)[len - 1];
				len--;
			}
		}
	}
	return (dest);
}
