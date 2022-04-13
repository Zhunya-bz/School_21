/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:41:47 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/16 13:55:41 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#define BUF_SIZE 30*1024 - 1
#define SIZE 1

void		ft_errors(char **argv, int i)
{
	ft_putstr("cat: ");
	ft_putstr(argv[i]);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putchar('\n');
}

void		ft_put_print(int argc)
{
	char array[SIZE + 1];

	while (argc == 1)
	{
		while (read(0, array, SIZE))
			ft_putchar(array[0]);
		ft_putchar('\n');
	}
}

void		ft_read_print(int op)
{
	int		ret;
	char	arr[BUF_SIZE + 1];

	ret = read(op, arr, BUF_SIZE);
	arr[ret] = '\0';
	ft_putstr(arr);
}

int			main(int argc, char **argv)
{
	int		op;
	int		i;

	i = 1;
	ft_put_print(argc);
	while (i < argc)
	{
		op = open(argv[i], O_RDONLY);
		if (op == -1)
		{
			ft_errors(argv, i);
			i++;
			continue;
		}
		else
		{
			ft_read_print(op);
		}
		if (close(op) == -1)
			ft_errors(argv, i);
		i++;
	}
	return (0);
}
