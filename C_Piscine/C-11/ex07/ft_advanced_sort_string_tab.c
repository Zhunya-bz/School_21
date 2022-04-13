/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:12:43 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/17 19:18:18 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_advanced_sort_string_tab(char **tab, int (*cmp) (char *, char *))
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
		if ((*cmp)(tab[i], tab[i + 1]))
		{
			w = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = w;
			i = 0;
		}
		i++;
	}
}
