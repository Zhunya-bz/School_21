#include "head_minishell.h"

int	g_stat;

static int	ft_str_spec_case(char *str)
{
	if (!ft_strcmp(str, ""))
	{
		if (str)
			free(str), str = NULL;
		return (1);
	}
	return (0);
}

void	ft_null_data(t_data *data)
{
	data->error = 0;
	data->fd_in = -1;
	data->fd_out = -1;
	data->ret_val = 0;
	data->total_cmd = 0;
	data->old_stat = 0;
	data->fl = 0;
	data->all_pid = NULL;
	data->fd_pipes = NULL;
	data->tmp = NULL;
	data->rez = NULL;
}

/*
**	@brief	Print errors fd = 2
**	
**	@param	str			message
**	@param	error_code	error code
**	@param	c			if fl = 1, char for message
**	@param	fl			if fl = 0 -> exit else if fl = 1 print message with c
**						else fl = 2 print str with newline
**	@return	int			error_code value
*/
int	ft_pr_error(char *str, int error_code, char c, int fl)
{
	if (!fl)
		ft_putendl_fd(str, 2), exit(error_code);
	else if (fl == 1)
	{
		ft_putstr_fd(str, 2), ft_putchar_fd('\'', 2);
		ft_putchar_fd(c, 2), ft_putendl_fd("'", 2);
	}
	else if (fl == 2)
		ft_putendl_fd(str, 2);
	else if (fl == 3)
	{
		ft_putstr_fd("minishell: ", 2), ft_putstr_fd(str, 2);
		ft_putendl_fd(": command not found", 2);
	}
	else if (fl == 4)
	{
		ft_putstr_fd("minishell: cd: ", 2), ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2), ft_putendl_fd(strerror(errno), 2);
	}
	else if (fl == 5)
		ft_putstr_fd("minishell: ", 2), ft_putendl_fd(strerror(errno), 2);
	else if (fl == 6)
		ft_putstr_fd("minishell: ", 2), ft_putendl_fd(str, 2);
	return (error_code);
}

char	*ft_pars_helper(char *rez)
{
	if (ft_count_words(rez, ' ') == 1 && ft_strlen(rez)
		&& rez[ft_strlen(rez) - 1] != ' ')
		rez = ft_strjoin_m(rez, " ", 1);
	return (rez);
}

/*
**	@brief	minishell start here
*/
int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*str;

	rl_outstream = stderr;
	if (ac != 1)
		return (0);
	ft_init_data(&data, env, NULL, av), ft_signal();
	while (TRUE)
	{
		str = readline(SHELL_FW);
		if (g_stat == 1)
		{
			data.ret_val = 1;
			g_stat = 0;
		}
		if (!str)
			str = ft_strdup("exit");
		if (ft_str_spec_case(str))
			continue ;
		add_history(str);
		if (!ft_parsing(&data, str, 0))
			ft_start_cmd(&data);
		ft_clean_all(str, data.cmd_start, 0, &data), data.fl = 0;
		data.cmd_start = NULL;
	}
}
