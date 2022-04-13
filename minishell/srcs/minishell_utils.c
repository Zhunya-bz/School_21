#include "head_minishell.h"

/*
**	@brief	Create env list with key and value
*/
t_env	*ft_new_env(char *key, char *val, unsigned char visible)
{
	t_env	*rez;

	rez = malloc(sizeof(t_env));
	if (!rez)
		ft_pr_error(ERR_MALC, -1, 0, 0);
	rez->key = key;
	rez->val = val;
	rez->visible = visible;
	rez->print = 0;
	rez->next = NULL;
	rez->prev = NULL;
	return (rez);
}

/*
**	@brief	Prepares the environment for using
**	
**	@param	data	struct t_data
**	@param	env		environment
**	@param	i 0		iterator(just because of the norm)
**	@param	len	0	iterator(just because of the norm)
*/
static void	ft_pool_env(t_data *data, int i, size_t len, char **av)
{
	t_env	*tmp;
	t_env	*buf;
	char	*val;

	if (!data->env)
		ft_null_env(data, av);
	while (data->env && data->env[i])
	{
		len = ft_strlen_m(data->env[i], '=');
		val = ft_strdup(&data->env[i][len + 1]);
		tmp = ft_new_env(ft_strndup(data->env[i], len), val, 0);
		i++;
		if (!data->beg_env)
		{
			data->beg_env = tmp;
			data->beg_env->prev = NULL;
			buf = data->beg_env;
			continue ;
		}
		buf->next = tmp;
		tmp->prev = buf;
		buf = buf->next;
	}
	data->env = NULL;
	data->count = 0;
}

/*
**	@brief	Initializes struct data
**	
**	@param	data	struct t_data
**	@param	env		environment
*/
void	ft_init_data(t_data *data, char **env, t_env *tmp, char **av)
{
	ft_null_data(data);
	data->env = env;
	ft_pool_env(data, 0, 0, av);
	tmp = data->beg_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "SHLVL"))
		{
			data->shlvl = ft_atoi(tmp->val) + 1, free(tmp->val);
			if (data->shlvl < 0)
				data->shlvl = 0;
			tmp->val = ft_itoa(data->shlvl);
		}
		if (!ft_strcmp(tmp->key, "OLDPWD"))
			free(tmp->val), tmp->val = NULL;
		if (!ft_strcmp(tmp->key, "PWD"))
			ft_pwd(data, 1, NULL);
		tmp = tmp->next;
	}
}

/*
**	@brief	Prepares the environment to run with the command
**			and fills out data->env_path
**	
**	@param	env		environment
**	@param	data	struct t_data
*/
char	**ft_proc_envp(t_data *data)
{
	t_env	*tmp;
	int		i;
	char	**rez;

	tmp = data->beg_env;
	while (tmp && ft_strcmp(tmp->key, "PATH"))
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	rez = ft_split(tmp->val, ':');
	if (!rez)
		ft_pr_error(ERR_MALC, -1, 0, 0);
	i = 0;
	while (rez[i])
		rez[i] = ft_strjoin_m(rez[i], "/", 1), i++;
	return (rez);
}

void	ft_env_to_char(t_data *data)
{
	t_env	*tmp;
	int		i;
	char	**rez;

	tmp = data->beg_env;
	i = 0;
	while (tmp)
	{
		if (tmp->visible == 0)
			i++;
		tmp = tmp->next;
	}
	rez = malloc(sizeof(char *) * (i + 1));
	i = 0;
	tmp = data->beg_env;
	while (tmp)
	{
		if (tmp->visible == 0)
			rez[i] = ft_strjoin_m(ft_strjoin_m(tmp->key, "=", 0),
					tmp->val, 1), i++;
		tmp = tmp->next;
	}
	rez[i] = NULL;
	data->env = rez;
}
