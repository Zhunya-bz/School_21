/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:29:29 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/11 22:08:43 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		compare(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] != '\0') || (s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

void	print_fun(int argc, char **argv)
{
	int i;
	int j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			ft_putchar(argv[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - 1)
		{
			if (compare(argv[j], argv[j + 1]) > 0)
			{
				c = argv[j + 1];
				argv[j + 1] = argv[j];
				argv[j] = c;
			}
			j++;
		}
		i++;
	}
	print_fun(argc, argv);
	return (0);
}
