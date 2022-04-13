#include "head_minishell.h"

void	ft_echo(t_cmd *cmd, int i, int check)
{
	int	fl;

	ft_predv_obrab(cmd), fl = 0;
	if (cmd->arg[1])
	{
		check = ft_echo_arg_check(cmd->arg[i]);
		if (!check)
			i++;
		while (cmd->arg[i] && !check && !fl)
		{
			fl = ft_echo_arg_check(cmd->arg[i]);
			if (fl)
				break ;
			i++;
		}
		while (cmd->arg[i])
		{
			ft_putstr_fd(cmd->arg[i], 1), i++;
			if (cmd->arg[i])
				write(1, " ", 1);
		}
	}
	if (check)
		write(1, "\n", 1);
	cmd->data->ret_val = 0;
}

static void	ft_pwd_helper(t_env *beg_env, char *str)
{
	t_env	*tmp;

	tmp = beg_env;
	while (tmp && ft_strcmp(tmp->key, "PWD"))
		tmp = tmp->next;
	if (tmp)
		printf("%s\n", tmp->val), free(str);
}

int	ft_pwd(t_data *data, int fl, t_cmd *cmd)
{
	char	*str;
	t_env	*tmp;

	(void)cmd;
	str = getcwd(NULL, PWD_LEN);
	str = ft_strjoin_m(NULL, str, 2);
	if (!fl)
	{
		if (str && !str[0])
			ft_pwd_helper(data->beg_env, str);
		else
			printf("%s\n", str), free(str);
		return (0);
	}
	tmp = data->beg_env;
	while (tmp && ft_strcmp(tmp->key, "PWD"))
		tmp = tmp->next;
	if (tmp)
		free(tmp->val), tmp->val = str;
	else
		free(str);
	return (0);
}

int	ft_env(t_cmd *cmd)
{
	t_env	*tmp;

	if (cmd->arg[1])
	{
		ft_pr_error("Error: env: support only one arg", 0, 0, 2);
		return (127);
	}
	tmp = cmd->data->beg_env;
	while (tmp)
	{
		if (!tmp->visible && tmp->val)
			ft_putstr_fd(tmp->key, 1), ft_putchar_fd('=', 1),
			ft_putendl_fd(tmp->val, 1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_unset(t_cmd *cmd, int i)
{
	t_env	*tmp;

	while (cmd->arg[++i])
	{
		if (ft_chek_env_key(cmd->arg[i], 0))
		{
			ft_pr_error("Error: unset: not a valid identifier", 0, 0, 2);
			return (1);
		}
		tmp = cmd->data->beg_env;
		while (tmp && ft_strcmp(tmp->key, cmd->arg[i]))
			tmp = tmp->next;
		if (!tmp)
			continue ;
		if (!tmp->prev)
			cmd->data->beg_env = tmp->next;
		else
			tmp->prev->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		free(tmp->key), tmp->key = NULL;
		free(tmp->val), tmp->val = NULL;
		free(tmp), tmp = NULL;
	}
	return (0);
}
