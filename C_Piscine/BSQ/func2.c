/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:58:39 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/24 23:20:01 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#define BUF_SIZE 30

void		go_to_lines(t_list *data)
{
	int i;

	i = 0;
	while (*(data->point_data) != 0)
	{
		data->size = 0;
		while (*(data->point_data) != '\n')
		{
			data->arr[i] =
			add_data(data->arr[i], data->point_data, data->size, 1);
			data->size++;
			data->point_data++;
		}
		data->point_data++;
		i++;
	}
}

void		print_numbers(t_list *data)
{
	int i;

	i = 0;
	while (data->str[i] != data->str[data->size - 3])
	{
		data->number[i] = data->str[i];
		i++;
	}
	data->number[i] = '\0';
	data->nb = ft_atoi(data->number);
}

void		print_error(t_list *data)
{
	int j;
	int i;

	i = 0;
	while (i < data->nb)
	{
		if ((i != 0) && ft_strlen(data->arr[i]) != ft_strlen(data->arr[0]))
		{
			ft_putstr("map error\n");
			break ;
		}
		j = 0;
		while (j < data->size)
		{
			if ((data->arr[i][j] != data->str[data->size - 3])
			&& (data->arr[i][j] != data->str[data->size - 2])
			&& (data->arr[i][j] == data->str[data->size - 1]))
			{
				ft_putstr("map error\n");
				break ;
			}
			j++;
		}
		i++;
	}
}

void		create_arr(t_list *data)
{
	int i;

	i = 0;
	data->arr = malloc(sizeof(char*) * data->nb);
	while (i < data->nb)
	{
		data->arr[i] = malloc(sizeof(char));
		i++;
	}
}

void		read_first_row(t_list *data)
{
	int	size;

	if (!(data->str = malloc(sizeof(char))))
		return ;
	*(data->str) = 0;
	size = 0;
	while (*(data->point_data) != '\n')
	{
		data->str = add_data(data->str, data->point_data, size, 1);
		size++;
		data->point_data++;
	}
	if (size < 4)
		ft_putstr("map error\n");
	data->size = size;
}
