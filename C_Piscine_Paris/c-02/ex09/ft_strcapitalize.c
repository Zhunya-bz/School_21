/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:48:56 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/19 13:16:56 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_is_alphanumeric(char str)
{
	if (!((str >= 'a' && str <= 'z')
			|| (str >= 'A' && str <= 'Z')
			|| (str >= '0' && str <= '9')))
	{
		return (0);
	}
	return (1);
}

int	ft_is_numeric(char str)
{
	if (!(str >= '0' && str <= '9'))
	{
		return (0);
	}
	return (1);
}

int	ft_is_lowercase(char str)
{
	if (!(str >= 'a' && str <= 'z'))
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_alphanumeric(str[i]) == 1)
		{
			if (ft_is_lowercase(str[i]) == 1)
				str[i] = str[i] - 32;
			i++;
			while (ft_is_alphanumeric(str[i]) == 1)
			{
				if (ft_is_lowercase(str[i]) == 1 || ft_is_numeric(str[i]) == 1)
					i++;
				else
				{
					str[i] = str[i] + 32;
					i++;
				}
			}
		}
		i++;
	}
	return (str);
}

/*
int main() {
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(str));
}*/
