/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:36:00 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/17 19:11:25 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			compare(char *s1, char *s2)
{
	int		i;

	i = 0;
	while ((s1[i] != '\0') || (s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

void		ft_sort_string_tab(char **tab)
{
	int		i;
	int		len;
	char	*w;

	i = 0;
	len = 0;
	while (tab[len] != '\0')
	{
		len++;
	}
	while (i < len - 1)
	{
		if (compare(tab[i], tab[i + 1]) >= 0)
		{
			w = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = w;
			i = 0;
		}
		i++;
	}
}
