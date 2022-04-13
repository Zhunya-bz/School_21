#include "head_minishell.h"

static char	*ft_points(t_cmd *do_cmd)
{
	char		*rez;
	t_env		*tmp;

	if (do_cmd->cmd && do_cmd->cmd[1] == '.' && do_cmd->cmd[2] == 0)
		return (NULL);
	if (ft_ch_for_coinc(do_cmd->cmd[0], "./"))
		return (ft_strdup(do_cmd->cmd));
	tmp = do_cmd->data->beg_env;
	while (tmp && ft_strcmp(tmp->key, "HOME"))
		tmp = tmp->next;
	if (tmp)
	{
		rez = ft_strjoin_m(tmp->val, ft_strdup(&do_cmd->cmd[1]), 2);
		free(do_cmd->arg[0]);
		do_cmd->arg[0] = ft_strdup(rez);
		do_cmd->cmd = do_cmd->arg[0];
		return (rez);
	}
	return (NULL);
}

char	*ft_find_cmd(t_cmd *do_cmd, int i)
{
	struct stat	buf;
	char		*try;
	char		**env_path;

	if (ft_ch_for_coinc(do_cmd->cmd[0], "./~"))
	{
		try = ft_points(do_cmd);
		if (try && stat(try, &buf))
			free(try), try = NULL;
		return (try);
	}
	env_path = ft_proc_envp(do_cmd->data);
	while (env_path && env_path[i])
	{
		try = ft_strjoin(env_path[i], do_cmd->cmd);
		if (!stat(try, &buf))
		{
			ft_free_split(env_path), env_path = NULL;
			return (try);
		}
		free(try), i++;
	}
	if (env_path)
		ft_free_split(env_path), env_path = NULL;
	return (NULL);
}

static void	ft_pool_helper(t_cmd *cmd, char *str, int *i)
{
	cmd->data->rez = NULL;
	cmd->next = NULL;
	cmd->pid = 0;
	cmd->dino = ft_strndup(&str[cmd->data->count], *i - cmd->data->count);
	cmd->data->count = *i + 1;
	cmd->tot_arg = 0;
	while (cmd->arg && cmd->arg[cmd->tot_arg])
		cmd->tot_arg += 1;
}

t_cmd	*ft_pool_new_cmd(t_data *data, char *str, int *i)
{
	t_cmd	*rez;

	rez = malloc(sizeof(t_cmd));
	rez->arg = ft_split(data->rez, ' ');
	rez->cmd = rez->arg[0];
	rez->ful_cmd = data->rez;
	rez->data = data;
	rez->fd_inf = data->fd_in;
	rez->fd_outf = data->fd_out;
	rez->tmp_fd[0] = -1;
	rez->tmp_fd[1] = -1;
	ft_pool_helper(rez, str, i);
	if (str[*i] != 0 && str[*i] == '|' && str[*i + 1] != '|')
		rez->delim = PIPE, (*i)++;
	else if (str[*i] != 0 && str[*i] == '&' && str[*i + 1] == '&')
		rez->delim = DOB_AMPER, (*i)++, (*i)++;
	else if (str[*i] != 0 && str[*i] == '|' && str[*i + 1] == '|')
		rez->delim = DOB_PIPE, (*i)++, (*i)++;
	else if (str[*i] != 0 && str[*i] == ';')
		rez->delim = POINT_ZAP, (*i)++;
	else
		rez->delim = 0;
	return (rez);
}

int	ft_pool_cmd(t_data *data, char *str, int *i)
{
	t_cmd	*tmp;

	if (!data->rez)
		return (1);
	if (!data->cmd_start)
	{
		data->cmd_start = ft_pool_new_cmd(data, str, i);
		data->cmd_start->num_start = data->total_cmd;
	}
	else
	{
		tmp = data->cmd_start;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_pool_new_cmd(data, str, i);
		tmp->next->num_start = data->total_cmd;
	}
	if (data->fd_in > 0)
		data->fd_in = -1;
	if (data->fd_out > 0)
		data->fd_out = -1;
	data->total_cmd++;
	return (0);
}
