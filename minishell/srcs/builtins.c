#include "head_minishell.h"

t_env	*ft_find_key(t_env *env)
{
	t_env	*tmp;
	t_env	*elem_sort;
	char	*str_tmp;
	int		dif;

	tmp = env;
	elem_sort = tmp;
	str_tmp = NULL;
	while (tmp)
	{
		if (!tmp->print)
		{
			dif = ft_strcmp(str_tmp, tmp->key);
			if (dif > 0)
			{
				elem_sort = tmp;
				str_tmp = tmp->key;
			}
		}
		tmp = tmp->next;
	}
	elem_sort->print = 1;
	return (elem_sort);
}

void	ft_start_own_prog(t_cmd *cmd, int fl)
{
	if (fl == 1)
		ft_echo(cmd, 1, 1);
	else if (fl == 2)
		cmd->data->ret_val = ft_pwd(cmd->data, 0, cmd);
	else if (fl == 3)
		cmd->data->ret_val = ft_env(cmd);
	else if (fl == 4)
		cmd->data->ret_val = ft_exit(cmd, 0);
	else if (fl == 5)
		cmd->data->ret_val = ft_unset(cmd, 0);
	else if (fl == 6)
		cmd->data->ret_val = ft_export(cmd, 0);
	else if (fl == 7)
		cmd->data->ret_val = ft_cd(cmd, NULL);
	else if (fl == 8)
		cmd->data->ret_val
			= ft_change_env(cmd, cmd->cmd, 1, 0);
	else
		ft_pr_error("Impossible", 0, 0, 2);
}

int	ft_buildin(t_cmd *cmd, int fl)
{
	fl = 0;
	if (!ft_strcmp(cmd->cmd, "echo"))
		fl = 1;
	else if (!ft_strcmp(cmd->cmd, "pwd"))
		fl = 2;
	else if (!ft_strcmp(cmd->cmd, "env"))
		fl = 3;
	else if (!ft_strcmp(cmd->cmd, "exit"))
		fl = 4;
	else if (!ft_strcmp(cmd->cmd, "unset"))
		fl = 5;
	else if (!ft_strcmp(cmd->cmd, "export"))
		fl = 6;
	else if (!ft_strcmp(cmd->cmd, "cd"))
		fl = 7;
	else if (ft_strlen_m(cmd->cmd, '='))
		fl = 8;
	return (fl);
}

int	ft_quotes_error(void)
{
	ft_pr_error("minishell: not closed quotes", 0, 0, 2);
	return (1);
}
