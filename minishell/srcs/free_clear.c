#include "head_minishell.h"

void	ft_free_cmd(t_cmd *do_cmd)
{
	t_cmd	*tmp;

	if (!do_cmd)
		return ;
	if (do_cmd->fd_inf > 0)
		close(do_cmd->fd_inf), do_cmd->fd_inf = -1;
	if (do_cmd->fd_outf > 0)
		close(do_cmd->fd_outf), do_cmd->fd_outf = -1;
	if (do_cmd->dino)
		free(do_cmd->dino), do_cmd->dino = NULL;
	if (do_cmd->arg)
		ft_free_split(do_cmd->arg), do_cmd->arg = NULL;
	if (do_cmd->ful_cmd)
		free(do_cmd->ful_cmd), do_cmd->ful_cmd = NULL;
	do_cmd->cmd = NULL;
	tmp = do_cmd->next;
	do_cmd->data->cmd_start = tmp;
	free(do_cmd), do_cmd = NULL;
}

/*
**	@brief	Free memory which was allocated
**	
**	@param	data	struct t_data
*/
void	ft_free_data(t_data *data)
{
	t_env	*tmp;
	t_env	*buf;

	tmp = data->beg_env;
	data->beg_env = NULL;
	while (tmp)
	{
		if (tmp->key)
			free(tmp->key), tmp->key = NULL;
		if (tmp->val)
			free(tmp->val), tmp->val = NULL;
		buf = tmp;
		tmp = tmp->next;
		free(buf);
	}
	ft_clean_all(NULL, data->cmd_start, 0, data);
	data = NULL;
}

static void	ft_clean_helper(t_data *data)
{
	close(data->fd_in), data->fd_in = -1;
	close(data->fd_out), data->fd_out = -1;
	if (data->fl)
		data->ret_val = 3;
}

void	ft_clean_all(char *str, t_cmd *start, int i, t_data *data)
{
	t_cmd	*tmp;

	if (str)
		free(str), str = NULL;
	if (data->rez)
		free(data->rez), data->rez = NULL;
	data->total_cmd = 0;
	data->count = 0;
	ft_clean_helper(data);
	if (data->all_pid)
		free(data->all_pid), data->all_pid = NULL;
	while (data->fd_pipes && data->fd_pipes[i])
		free(data->fd_pipes[i]), data->fd_pipes[i] = NULL, i++;
	if (data->fd_pipes)
		free(data->fd_pipes), data->fd_pipes = NULL;
	if (!start)
		return ;
	tmp = start;
	tmp->data->cmd_start = NULL;
	while (tmp)
	{
		start = tmp->next, ft_free_cmd(tmp);
		tmp = start;
	}
}

void	ft_null_env(t_data *data, char **av)
{
	t_env	*start;
	char	*str;

	start = ft_new_env(ft_strdup("SHLVL"), ft_strdup("1"), 1);
	start->next = ft_new_env(ft_strdup("_"), ft_strdup(av[0]), 1);
	str = getcwd(NULL, PWD_LEN);
	start->next->next = ft_new_env(ft_strdup("PWD"), str, 1);
	data->beg_env = start;
}
