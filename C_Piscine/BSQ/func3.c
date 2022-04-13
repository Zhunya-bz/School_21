/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:01:27 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/24 23:15:48 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#define BUF_SIZE 30

void		print_x(t_list *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->nb)
	{
		j = 0;
		while (j < data->size)
		{
			if ((j > data->j_index - data->max) && (j <= data->j_index) &&
			(i > data->i_index - data->max) && (i <= data->i_index))
				write(1, &(data->x), 1);
			else
				write(1, &data->arr[i][j], 1);
			j++;
		}
		i++;
		ft_putstr("\n");
	}
}

void		algoritm(t_list *data)
{
	int i;

	i = 1;
	data->max = 0;
	while (i < data->nb)
	{
		algoritm1(data, i);
		i++;
	}
}

void		algoritm1(t_list *data, int i)
{
	int j;

	j = 1;
	while (j < data->size)
	{
		data->min = data->mat[i - 1][j];
		if (data->mat[i][j - 1] < data->min)
			data->min = data->mat[i][j - 1];
		else if (data->mat[i - 1][j - 1] < data->min)
			data->min = data->mat[i - 1][j - 1];
		if (data->mat[i][j] == 0)
			data->mat[i][j] = 0;
		else
		{
			data->mat[i][j] = data->min + 1;
			if (data->mat[i][j] > data->max)
			{
				data->max = data->mat[i][j];
				data->i_index = i;
				data->j_index = j;
			}
		}
		j++;
	}
}

void		create_mat(t_list *data)
{
	int i;
	int j;

	i = 0;
	data->mat = malloc(sizeof(int *) * data->nb);
	while (i < data->nb)
	{
		data->mat[i] = malloc(data->size * sizeof(int));
		i++;
	}
	i = 0;
	while (i < data->nb)
	{
		j = 0;
		while (j < data->size)
		{
			if (data->arr[i][j] == data->empty)
				data->mat[i][j] = 1;
			else
				data->mat[i][j] = 0;
			j++;
		}
		i++;
	}
}

void		put_error(t_list *data)
{
	data->x = data->str[data->size - 1];
	data->op = data->str[data->size - 2];
	data->empty = data->str[data->size - 3];
	if ((data->x == data->op) || (data->x == data->empty)
	|| (data->op == data->empty))
		ft_putstr("map error\n");
}
