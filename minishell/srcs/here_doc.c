#include "head_minishell.h"

static void	ft_heredoc_helper(char *line, t_data *data, char *stoper, int fd[2])
{
	if (line)
		free(line), line = NULL;
	if (data && data->fd_in > 0)
		close(data->fd_in), data->fd_in = -1;
	if (stoper)
		free(stoper), stoper = NULL;
	close(fd[1]);
	data->fd_in = fd[0];
}

static void	ft_signal_cltr_c(int sig)
{
	int	i;

	(void)sig;
	i = 0;
	while (i < 10)
		write(2, "\b\b\b\b\b\b\b\b\b\b", 10), i++;
	exit(1);
}

static void	ft_signal_hd(void)
{
	signal(SIGQUIT, ft_signal_pipe);
	signal(SIGINT, ft_signal_cltr_c);
}

static void	ft_child(int fd[2], char *stop)
{
	char	*line;

	line = NULL;
	close(fd[0]), ft_signal_hd();
	while (TRUE)
	{	
		line = readline(">");
		if (!ft_strcmp(line, stop) || !line)
			break ;
		ft_putendl_fd(line, fd[1]), free(line), line = NULL;
	}
	if (stop)
		free(stop), stop = NULL;
	if (line)
		free(line), line = NULL;
	close(fd[1]), exit(0);
}

/*
**	@brief	Create pipe and read there from fd = 0 until stop_world
**	
**	@param	data	struct t_data
**	@param	str		string from readline
**	@param	i		where str now
*/
int	ft_here_doc(t_data *data, char *str, int *i, char *stop)
{
	int	fd[2];
	int	flag;
	int	check;

	*i = *i + 2;
	while (str[*i] && str[*i] == ' ')
		*i = *i + 1;
	while (str[*i] && !ft_ch_for_coinc(str[*i], "> <|&;"))
		stop = ft_proc_open(data, str, i, stop);
	if (!stop)
	{
		data->ret_val = 1, ft_pr_error(ERR_SH_NEWL, 0, 0, 2);
		return (1);
	}
	pipe(fd), check = 0;
	flag = fork();
	if (flag < 0)
		ft_pr_error(ERR_FORK, -1, 0, 0);
	else if (!flag)
		ft_child(fd, stop);
	waitpid(flag, &check, 0);
	ft_heredoc_helper(NULL, data, stop, fd);
	if (check)
		return (1);
	return (0);
}
