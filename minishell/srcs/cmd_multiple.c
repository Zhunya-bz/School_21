#include "head_minishell.h"

static void	ft_first_helper(t_cmd *cmd)
{
	int	i;

	close(cmd->data->fd_pipes[0][0]), cmd->data->fd_pipes[0][0] = -1;
	i = 1;
	while (cmd->data->fd_pipes && cmd->data->fd_pipes[i])
	{
		close(cmd->data->fd_pipes[i][0]), cmd->data->fd_pipes[i][0] = -1;
		close(cmd->data->fd_pipes[i][1]), cmd->data->fd_pipes[i][1] = -1;
		i++;
	}
}

static void	ft_first_cmd(t_cmd *cmd)
{
	char	*cmd_s;

	ft_first_helper(cmd), cmd->fl = ft_buildin(cmd, 0);
	if (cmd->fd_outf > 0)
		close(cmd->data->fd_pipes[cmd->num_start][1]);
	else
		cmd->fd_outf = cmd->data->fd_pipes[cmd->num_start][1];
	cmd->data->fd_pipes[cmd->num_start][1] = -1;
	ft_redirects(cmd, 0);
	if (cmd->fl)
		ft_start_own_prog(cmd, cmd->fl);
	else
	{
		cmd_s = ft_find_cmd(cmd, 0);
		execve(cmd_s, cmd->arg, cmd->data->env), free(cmd_s);
		ft_pr_error(NULL, 0, 0, 5), cmd->data->ret_val = 1;
	}
	ft_redirects(cmd, 1), exit(cmd->data->ret_val);
}

static void	ft_child(t_cmd *cmd)
{
	char	*cmd_s;

	ft_close_pipes(cmd->data, cmd, cmd->num_start);
	cmd->fl = ft_buildin(cmd, 0);
	if (cmd->fd_inf > 0)
		close(cmd->data->fd_pipes[cmd->num_start - 1][0]);
	else
		cmd->fd_inf = cmd->data->fd_pipes[cmd->num_start - 1][0];
	cmd->data->fd_pipes[cmd->num_start - 1][0] = -1;
	if (cmd->fd_outf > 0)
		close(cmd->data->fd_pipes[cmd->num_start][1]);
	else
		cmd->fd_outf = cmd->data->fd_pipes[cmd->num_start][1];
	cmd->data->fd_pipes[cmd->num_start][1] = -1;
	ft_redirects(cmd, 0);
	if (cmd->fl)
		ft_start_own_prog(cmd, cmd->fl);
	else
	{
		cmd_s = ft_find_cmd(cmd, 0);
		execve(cmd_s, cmd->arg, cmd->data->env), free(cmd_s);
		ft_pr_error(NULL, 0, 0, 5), cmd->data->ret_val = 1;
	}
	ft_redirects(cmd, 1), exit(cmd->data->ret_val);
}

static void	ft_last_cmd(t_cmd *cmd)
{
	char	*cmd_s;

	ft_close_pipes(cmd->data, cmd, cmd->num_start);
	cmd->fl = ft_buildin(cmd, 0);
	if (cmd->fd_inf > 0)
		close(cmd->data->fd_pipes[cmd->num_start - 1][0]);
	else
		cmd->fd_inf = cmd->data->fd_pipes[cmd->num_start - 1][0];
	cmd->data->fd_pipes[cmd->num_start - 1][0] = -1;
	ft_redirects(cmd, 0);
	if (cmd->fl)
		ft_start_own_prog(cmd, cmd->fl);
	else
	{
		cmd_s = ft_find_cmd(cmd, 0);
		execve(cmd_s, cmd->arg, cmd->data->env), free(cmd_s);
		ft_pr_error(NULL, 0, 0, 5), cmd->data->ret_val = 1;
	}
	ft_redirects(cmd, 1), exit(cmd->data->ret_val);
}

void	ft_multiple_cmd(t_cmd *cmd, int i, int fl)
{
	t_cmd	*tmp;

	tmp = cmd->data->cmd_start, ft_create_pipes(cmd->data);
	while (tmp && !cmd->data->fl)
	{
		if (tmp->delim != PIPE && tmp->delim != 0)
			ft_pr_error("Sorry not supported yeat", -1, 0, 0);
		fl = fork();
		if (fl < 0)
			ft_pr_error(ERR_FORK, -1, 0, 0);
		if (!fl)
		{
			if (ft_cmd_check(cmd))
				ft_pr_error(ERR_CMD, 0, 0, 2), exit(100);
			if (!tmp->next)
				ft_last_cmd(tmp);
			else if (!tmp->num_start)
				ft_first_cmd(tmp);
			else if (tmp->next)
				ft_child(tmp);
		}
		cmd->data->all_pid[i] = fl;
		tmp = tmp->next, i++;
	}
	ft_close_all(cmd->data), ft_wait_all_cmd(cmd->data);
}
