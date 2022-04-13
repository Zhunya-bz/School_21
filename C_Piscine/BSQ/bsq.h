/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:06:51 by wtandoor          #+#    #+#             */
/*   Updated: 2021/03/24 23:29:57 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct	s_list
{
	int			size;
	int			fd;
	int			ret;
	char		*all_data;
	char		*point_data;
	char		*str;
	char		x;
	char		op;
	char		empty;
	char		number[10];
	int			nb;
	char		**arr;
	int			**mat;
	int			min;
	int			max;
	int			i_index;
	int			j_index;
}				t_list;

void			ft_putstr(char *str);
int				ft_atoi(char *str);
char			*add_data(char *old_arr, char *buf, int all_size, int ret);
int				ft_strlen(char *str);
char			*work_file(char **argv, char *all_data, int argc);
void			print_x(t_list *data);
void			algoritm(t_list *data);
void			create_mat(t_list *data);
void			put_error(t_list *data);
void			go_to_lines(t_list *data);
void			print_numbers(t_list *data);
void			print_error(t_list *data);
void			algoritm1(t_list *data, int i);
void			create_arr(t_list *data);
void			read_first_row(t_list *data);

#endif
