/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:12:29 by wtandoor          #+#    #+#             */
/*   Updated: 2021/03/24 23:32:58 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#define BUF_SIZE 30

void				ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int					ft_atoi(char *str)
{
	unsigned int	i;
	int				res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '-') || (str[i] < '0') || (str[i] > '9'))
		{
			ft_putstr("map error\n");
			return (0);
		}
		res *= 10;
		res += (int)str[i] - '0';
		i++;
	}
	return (res);
}

char				*add_data(char *old_arr, char *buf, int all_size, int ret)
{
	char *new_arr;
	char *temp;
	char *old_temp;

	new_arr = malloc(all_size + ret + 1);
	temp = new_arr;
	old_temp = old_arr;
	while (all_size-- != 0)
		*temp++ = *old_temp++;
	while (ret-- != 0)
		*temp++ = *buf++;
	*temp = 0;
	return (new_arr);
}

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char				*work_file(char **argv, char *all_data, int argc)
{
	int				fd;
	int				size;
	int				ret;
	char			buf[BUF_SIZE];

	all_data = malloc(sizeof(char) * BUF_SIZE);
	*all_data = 0;
	size = 0;
	if (argc == 1)
		fd = 0;
	else 
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putstr(strerror(errno));
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		all_data = add_data(all_data, buf, size, ret);
		size += ret;
	}
	if (close(fd) == -1)
		ft_putstr(strerror(errno));
	return (all_data);
}
