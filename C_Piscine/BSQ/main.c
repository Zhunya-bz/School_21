/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:51:28 by saltmer           #+#    #+#             */
/*   Updated: 2021/03/24 23:30:06 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#define BUF_SIZE 30

int			main(int argc, char **argv)
{
	t_list	data;

	data.all_data = work_file(argv, data.all_data, argc);
	data.point_data = data.all_data;
	data.str = malloc(sizeof(char));
	*(data.str) = 0;
	read_first_row(&data);
	put_error(&data);
	print_numbers(&data);
	data.point_data++;
	create_arr(&data);
	go_to_lines(&data);
	print_error(&data);
	create_mat(&data);
	algoritm(&data);
	print_x(&data);
	free(data.arr);
	free(data.mat);
	free(data.str);
	return (0);
}
