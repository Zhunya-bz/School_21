/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:55:48 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/17 19:30:45 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <unistd.h>

void	put(int i, int nb, char a, char *arr);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		plus(int a, int b);
int		minus(int a, int b);
int		multi(int a, int b);
int		devide(int a, int b);
int		f_module(int a, int b);

#endif
