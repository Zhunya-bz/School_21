/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:52:13 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/15 20:28:30 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define BUF 4096

void		ft_error(int argc)
{
	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
	}
}

int			main(int argc, char **argv)
{
	int		op;
	int		ret;
	char	arr[BUF + 1];

	ft_error(argc);
	if (argc == 2)
	{
		op = open(argv[1], O_RDONLY);
		if (op == -1)
			ft_putstr("Cannot read file.\n");
		else
		{
			ret = read(op, arr, BUF);
			arr[ret] = '\0';
			ft_putstr(arr);
		}
		close(op);
	}
	return (0);
}
