#include "head_minishell.h"

static int	ft_open_app_read(t_data *data, char *f_name, int fl)
{
	int	fd;

	if (!f_name)
		return (-1);
	if (fl == 1)
		fd = open(f_name, O_WRONLY | O_CREAT | O_APPEND, 0664);
	else if (fl == 2)
		fd = open(f_name, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	else if (fl == 3)
		fd = open(f_name, O_RDONLY);
	else
		fd = -1;
	free(f_name), f_name = NULL;
	if (fd == -1)
	{
		ft_pr_error(NULL, 0, 0, 5), data->ret_val = 1;
		return (-1);
	}
	if (fl == 1 || fl == 2)
		data->fd_out = fd;
	else if (fl == 3)
		data->fd_in = fd;
	return (0);
}

static int	ft_general_open(t_data *data, char *str, int *i, int fl)
{
	int		j;
	char	*f_name;

	f_name = NULL;
	if ((fl == 1 || fl == 2) && data->fd_out >= 0)
		close(data->fd_out), data->fd_out = -1;
	else if (fl == 3 && data->fd_in >= 0)
		close(data->fd_in);
	if (str[*i] && (str[*i] == '|' || str[*i] == '&'))
		*i = *i + 1;
	while (str[*i] && ft_ch_for_coinc(str[*i], " \t"))
		*i = *i + 1;
	j = *i;
	while (str[*i] && !ft_ch_for_coinc(str[*i], "> <|&;"))
		f_name = ft_proc_open(data, str, i, f_name);
	if (j == *i || !f_name)
	{
		ft_pr_error(ERR_SH_NEWL, 0, 0, 2), data->ret_val = 2;
		return (-2);
	}
	while (str[*i] && str[*i] == ' ')
		*i = *i + 1;
	return (ft_open_app_read(data, f_name, fl));
}

static int	ft_open_app_here(t_data *data, char *str, int *i)
{
	if (ft_ch_for_coinc(str[*i + 2], ";><"))
	{
		ft_pr_error(ERR_SH_TKN, 0, str[*i + 2], 1), data->ret_val = 2;
		return (-1);
	}
	else if (ft_ch_for_coinc(str[*i + 2], "\n\0"))
	{
		ft_pr_error(ERR_SH_NEWL, 0, 0, 2), data->ret_val = 2;
		return (-2);
	}
	else if (str[*i] == '>' && str[*i + 1] == '>')
	{
		*i = *i + 2;
		return (ft_general_open(data, str, i, 1));
	}
	else if (str[*i] == '<' && str[*i + 1] == '<')
		return (ft_here_doc(data, str, i, NULL));
	else
	{
		ft_pr_error(ERR_SH_TKN, 0, str[*i + 2], 1), data->ret_val = 2;
		return (-6);
	}
}

static int	ft_open_file(t_data *data, char *str, int *i)
{
	if (ft_ch_for_coinc(str[*i + 1], ";"))
	{
		ft_pr_error(ERR_SH_TKN, 0, str[*i + 2], 1), data->ret_val = 2;
		return (-1);
	}
	if (ft_ch_for_coinc(str[*i + 1], "\0\n"))
	{
		ft_pr_error(ERR_SH_NEWL, 0, str[*i + 2], 1), data->ret_val = 2;
		return (-2);
	}
	else if (str[*i] == '>')
	{
		*i = *i + 1;
		return (ft_general_open(data, str, i, 2));
	}
	*i = *i + 1;
	return (ft_general_open(data, str, i, 3));
}

int	ft_redir(t_data *data, char *str, int *i, int ans)
{
	if ((str[*i] == '<' || str[*i] == '>')
		&& (str[*i + 1] == '<' || str[*i + 1] == '>'))
	{
		ans = ft_open_app_here(data, str, i);
		if (!data->rez && !ans && !str[*i])
			return (ft_redir_helper(data));
		if (ans && data->rez)
			free(data->rez), data->rez = NULL;
	}
	else if ((str[*i] == '>' || str[*i] == '<'))
	{
		ans = ft_open_file(data, str, i);
		if (!data->rez && !ans && !str[*i])
			return (ft_redir_helper(data));
		if (ans && data->rez)
			free(data->rez), data->rez = NULL;
	}
	else if ((str[*i] == '|' || str[*i] == '&' || str[*i] == ';') && data->rez)
		ans = ft_pool_cmd(data, str, i);
	else
	{
		data->ret_val = 2, ft_pr_error(ERR_SH_TKN, 0, 0, 2);
		ans = 2;
	}
	return (ans);
}
