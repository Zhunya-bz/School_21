#include "head_minishell.h"

void	ft_create_pipes(t_data *data)
{
	int	i;

	data->fl = 0;
	data->fd_pipes = malloc(sizeof(int *) * (data->total_cmd));
	i = 0;
	while (i < data->total_cmd - 1)
	{
		data->fd_pipes[i] = malloc(sizeof(int) * 2);
		if (data->fd_pipes[i])
		{
			if (pipe(data->fd_pipes[i]))
			{
				ft_pr_error(ERR_PIPE, 0, 0, 2), data->fl = 1;
				free(data->fd_pipes[i]), data->fd_pipes[i] = NULL;
				return ;
			}
		}
		else
			ft_pr_error(ERR_MALC, -1, 0, 0);
		i++;
	}
	data->fd_pipes[i] = NULL;
	if (!data->fl)
		data->all_pid = malloc(sizeof(int) * (data->total_cmd));
}

void	ft_close_pipes(t_data *data, t_cmd *cmd, int pipe_num)
{
	int	i;

	i = 0;
	pipe_num -= 1;
	while (data->fd_pipes[i] && data->fd_pipes[i + 1])
	{
		if (i != pipe_num)
			close(data->fd_pipes[i + 1][1]), data->fd_pipes[i + 1][1] = -1;
		i++;
	}
	if (data->fd_pipes[0] && pipe_num != -1)
		close(data->fd_pipes[0][1]), data->fd_pipes[0][1] = -1;
	i = 0;
	while (data->fd_pipes[i])
	{
		if (i != pipe_num)
			close(data->fd_pipes[i][0]), data->fd_pipes[i][0] = -1;
		i++;
	}
	if (data->fd_pipes[pipe_num] && cmd->fd_inf > 0)
		close(data->fd_pipes[pipe_num][0]), data->fd_pipes[pipe_num][0] = -1;
	pipe_num++;
	if (data->fd_pipes[pipe_num] && cmd->fd_outf > 0)
		close(data->fd_pipes[pipe_num][1]), data->fd_pipes[pipe_num][1] = -1;
}

void	ft_redirects(t_cmd *cmd, int fl)
{
	if (!fl)
		ft_env_to_char(cmd->data);
	else
		ft_free_split(cmd->data->env);
	if (cmd->fd_inf < 0 && cmd->fd_outf < 0
		&& cmd->tmp_fd[1] < 0 && cmd->tmp_fd[0] < 0)
		return ;
	if (!fl)
	{
		cmd->tmp_fd[1] = dup(STDOUT);
		cmd->tmp_fd[0] = dup(STDIN);
		if (cmd->fd_inf > 0)
			dup2(cmd->fd_inf, STDIN), close(cmd->fd_inf), cmd->fd_inf = -1;
		if (cmd->fd_outf > 0)
			dup2(cmd->fd_outf, STDOUT), close(cmd->fd_outf), cmd->fd_outf = -1;
	}
	else
	{
		close(STDIN), close(STDOUT), dup2(cmd->tmp_fd[1], STDOUT);
		close(cmd->tmp_fd[1]), cmd->tmp_fd[1] = -1;
		dup2(cmd->tmp_fd[0], STDIN);
		close(cmd->tmp_fd[0]), cmd->tmp_fd[0] = -1;
	}
}

int	ft_redir_helper(t_data *data)
{
	close(data->fd_in);
	close(data->fd_out);
	data->ret_val = 1;
	data->fd_in = -1;
	data->fd_out = -1;
	return (1);
}

void	ft_close_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->fd_pipes && data->fd_pipes[i])
	{
		close(data->fd_pipes[i][0]), data->fd_pipes[i][0] = -1;
		close(data->fd_pipes[i][1]), data->fd_pipes[i][1] = -1;
		i++;
	}
}
