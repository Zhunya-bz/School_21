/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:51:36 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/17 17:14:24 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void		dop(char **tab, int (*f[5]) (int, int))
{
	char	*r;

	r = tab[2];
	if ((*r != '+') && (*r != '-') && (*r != '/') && (*r != '*') && (*r != '%'))
		return ;
	if (*r == '+')
		ft_putnbr((*f[0])(ft_atoi(tab[1]), ft_atoi(tab[3])));
	if (*r == '-')
		ft_putnbr((*f[1])(ft_atoi(tab[1]), ft_atoi(tab[3])));
	if (*r == '*')
		ft_putnbr((*f[2])(ft_atoi(tab[1]), ft_atoi(tab[3])));
	if (*r == '/')
	{
		if (ft_atoi(tab[3]) == 0)
			ft_putstr("Stop : division by zero\n");
		else
			ft_putnbr((*f[3])(ft_atoi(tab[1]), ft_atoi(tab[3])));
	}
	if (*r == '%')
	{
		if (ft_atoi(tab[3]) == 0)
			ft_putstr("Stop : modulo by zero\n");
		else
			ft_putnbr((*f[4])(ft_atoi(tab[1]), ft_atoi(tab[3])));
	}
}

int			main(int argc, char **argv)
{
	int (*f[5])(int, int);

	f[0] = &plus;
	f[1] = &minus;
	f[2] = &multi;
	f[3] = &devide;
	f[4] = &f_module;
	if (argc == 4)
		dop(argv, f);
	return (0);
}
