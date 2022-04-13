#include "head_minishell.h"

static int	ft_print_export(t_env *env)
{
	t_env	*tmp;
	t_env	*elem_sort;

	tmp = env;
	while (tmp)
	{
		elem_sort = ft_find_key(env);
		if (!elem_sort->visible && elem_sort->val)
			ft_putstr_fd("declare -x ", 1), ft_putstr_fd(elem_sort->key, 1),
			ft_putstr_fd("=\"", 1), ft_putstr_fd(elem_sort->val, 1),
			ft_putendl_fd("\"", 1);
		else if (!elem_sort->visible && !elem_sort->val)
			ft_putstr_fd("declare -x ", 1), ft_putendl_fd(elem_sort->key, 1);
		tmp = tmp->next;
	}
	tmp = env;
	while (tmp)
	{
		tmp->print = 0;
		tmp = tmp->next;
	}
	return (0);
}

int	ft_skip_fw(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ' )
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

static void	ft_export_helper(t_cmd *cmd)
{
	int		i;
	int		j;
	char	*rez;

	rez = NULL;
	if (!ft_strlen_m(cmd->dino, '"') && !ft_strlen_m(cmd->dino, '\''))
		return ;
	ft_free_split(cmd->arg), cmd->cmd = NULL;
	cmd->arg = malloc(sizeof(char *) * PWD_LEN);
	cmd->arg[0] = ft_strdup("export");
	cmd->cmd = cmd->arg[0];
	j = 1;
	i = ft_skip_fw(cmd->dino);
	while (cmd->dino[i])
	{
		rez = ft_proc_open(cmd->data, cmd->dino, &i, rez);
		cmd->arg[j] = rez, j++;
		rez = NULL;
		while (cmd->dino[i] && cmd->dino[i] == ' ')
			i++;
	}
	cmd->arg[j] = NULL;
}

static int	ft_chek_env_export(t_data *data, char *str)
{
	t_env	*tmp;

	tmp = data->beg_env;
	while (tmp)
	{
		if (!ft_strcmp(str, tmp->key))
		{
			tmp->visible = 0;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_export(t_cmd *cmd, int i)
{
	if (!cmd->arg[1])
		return (ft_print_export(cmd->data->beg_env));
	ft_export_helper(cmd);
	while (cmd->arg[++i])
	{
		if (ft_chek_env_key(cmd->arg[i], 1))
		{
			cmd->data->ret_val = 1, ft_pr_error(ERR_EXP, 0, 0, 2);
			return (1);
		}
		if (ft_strlen_m(cmd->arg[i], '=') || ft_strlen_m(cmd->arg[i], '+'))
			ft_change_env(cmd, cmd->arg[i], 0, 0);
		else if (ft_chek_env_export(cmd->data, cmd->arg[i]))
			continue ;
		else
		{
			cmd->data->beg_env->prev
				= ft_new_env(ft_strdup(cmd->arg[i]), NULL, 0);
			cmd->data->beg_env->prev->next = cmd->data->beg_env;
			cmd->data->beg_env = cmd->data->beg_env->prev;
		}
	}
	return (0);
}
