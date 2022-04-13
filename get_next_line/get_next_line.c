/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltmer <saltmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:30:33 by saltmer           #+#    #+#             */
/*   Updated: 2021/05/02 19:25:26 by saltmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#define BUFFER_SIZE 9999

static char	*check_rem_n(char **rem, char **p_to_n, char **line, char **tmp)
{
	*p_to_n = ft_strchr(*rem, '\n');
	if (*p_to_n != 0)
	{
		**p_to_n = '\0';
		*line = ft_strdup(*tmp);
		*rem = ft_strdup(++(*p_to_n));
		free(*tmp);
		if (!line || !rem)
			return (NULL);
	}
	else
	{
		*line = *rem;
		*rem = NULL;
	}
	return (*line);
}

static char	**check_remainder(char **rem, char **p_to_n, char **line)
{
	char	*tmp;

	tmp = *rem;
	if (*rem)
	{
		*line = check_rem_n(rem, p_to_n, line, &tmp);
		if (!line)
			return (NULL);
	}
	else
	{
		*line = ft_strdup("");
		if (!line)
			return (NULL);
	}
	return (line);
}

static int	read_write(char **line, char **buf, char **p_to_n, char **rem)
{
	char	*tmp;

	*p_to_n = ft_strchr(*buf, '\n');
	if (*p_to_n != 0)
	{
		**p_to_n = '\0';
		*rem = ft_strdup(++(*p_to_n));
		if (*rem == NULL)
			return (-1);
	}
	tmp = *line;
	*line = ft_strjoin(tmp, *buf);
	free(tmp);
	if (*line == NULL)
		return (-1);
	return (1);
}

static int	check_conditions(int fd, char **line, char **buf)
{
	if (!line || (fd < 0) || (BUFFER_SIZE <= 0))
		return (-1);
	*buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (-1);
	if (read(fd, *buf, 0) == -1)
	{
		free(*buf);
		return (-1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*p_to_n;
	int			rd;
	static char	*rem;
	char		*buf;

	p_to_n = NULL;
	rd = -2;
	if (check_conditions(fd, line, &buf) == -1)
		return (-1);
	line = check_remainder(&rem, &p_to_n, line);
	if (line == NULL)
		return (-1);
	while ((!p_to_n))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == 0)
			break ;
		buf[rd] = '\0';
		if (read_write(line, &buf, &p_to_n, &rem) == -1)
			return (-1);
	}
	free(buf);
	if ((rd == 0) || !p_to_n)
		return (0);
	return (1);
}
