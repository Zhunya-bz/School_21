#include "head_minishell.h"

void	ft_change_oldpwd(t_cmd *cmd, int fl)
{
	t_env	*tmp;

	if (!fl)
	{
		cmd->data->tmp = getcwd(NULL, PWD_LEN);
		cmd->data->tmp = ft_strjoin_m(NULL, cmd->data->tmp, 2);
	}
	else if (fl == 1)
	{
		tmp = cmd->data->beg_env;
		while (tmp && ft_strcmp(tmp->key, "OLDPWD"))
			tmp = tmp->next;
		if (tmp)
			free(tmp->val), tmp->val = cmd->data->tmp;
		else
			free(cmd->data->tmp), cmd->data->tmp = NULL;
	}
}

static int	ft_go_key(t_cmd *cmd, t_env *tmp, char *str_key, int fl)
{
	tmp = cmd->data->beg_env;
	while (tmp && ft_strcmp(str_key, tmp->key))
		tmp = tmp->next;
	if (tmp)
	{
		if (chdir(tmp->val) == -1)
		{
			free(cmd->data->tmp), cmd->data->tmp = NULL;
			ft_pr_error(cmd->arg[1], 0, 0, 4);
			return (1);
		}
		ft_pwd(cmd->data, fl, cmd);
	}
	else
	{
		free(cmd->data->tmp), cmd->data->tmp = NULL;
		ft_pr_error(str_key, 0, 0, 4);
		return (1);
	}
	return (0);
}

int	ft_cd(t_cmd *cmd, t_env *tmp)
{
	ft_change_oldpwd(cmd, 0);
	if (!cmd->arg[1] || !ft_strcmp(cmd->arg[1], "~"))
	{
		if (ft_go_key(cmd, tmp, "HOME", 1))
			return (1);
	}
	else if (!cmd->arg[1] || !ft_strcmp(cmd->arg[1], "-"))
	{
		if (ft_go_key(cmd, tmp, "OLDPWD", 0))
			return (1);
	}
	else
	{
		if (chdir(cmd->arg[1]) == -1)
		{
			ft_pr_error(cmd->arg[1], 0, 0, 4);
			return (1);
		}
		ft_pwd(cmd->data, 1, cmd);
	}
	ft_change_oldpwd(cmd, 1);
	return (0);
}
