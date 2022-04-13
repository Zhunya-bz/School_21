#include "libft.h"

static char	*ft_format_line(char *str)
{
	int		i;
	char	*rez;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	rez = malloc(sizeof(char) * (i + 1));
	if (!rez)
	{
		free(str);
		return (NULL);
	}
	rez[i] = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		rez[i] = str[i], i++;
	return (rez);
}

static char	*ft_saver(char *ost, int *fl, int i)
{
	char	*rez;
	int		j;

	while (ost[i] && ost[i] != '\n')
		i++;
	if (!ost[i])
	{
		*fl = 1, free(ost);
		return (NULL);
	}
	rez = malloc(sizeof(char) * (ft_strlen_m(ost, 0) - i + 1));
	if (!rez)
	{
		free(ost);
		return (NULL);
	}
	j = 0;
	while (ost[i++])
		rez[j++] = ost[i];
	rez[j] = 0, free(ost);
	return (rez);
}

static int	ft_helper(char *buf, int *rdr, int fd)
{
	*rdr = read(fd, buf, BUFFER_SIZE);
	if (*rdr == -1)
	{
		if (buf)
			free(buf), buf = NULL;
		return (1);
	}
	buf[*rdr] = 0;
	return (0);
}

static int	ft_helper_dop(char *buf, char **ost, char ***line, int *fl)
{
	if (buf)
		free(buf), buf = NULL;
	**line = ft_format_line(*ost);
	if (!(**line))
		return (1);
	*fl = 0;
	*ost = ft_saver(*ost, fl, 0);
	if (!(*fl) && !(*ost))
		return (1);
	return (0);
}

/*
**	@brief	Creates array of strings using the character ’\n’ as a delimiter,
**			read string from fd.
**	
**	@param	fd		pointer to string
**	@param	line	delimiter character
**	@return	int		counts substrings
*/
int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*ost[FD_SIZE];
	int			rdr;
	int			fl;

	if (fd > FD_SIZE || fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	rdr = 1;
	while (ft_gnl_cheker(ost[fd]) && rdr)
	{
		if (ft_helper(buf, &rdr, fd))
			return (-1);
		ost[fd] = ft_strjoin_m(ost[fd], buf, 1);
	}
	if (ft_helper_dop(buf, &ost[fd], &line, &fl))
		return (-1);
	if (!rdr && fl)
		return (0);
	return (1);
}
