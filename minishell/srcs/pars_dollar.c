#include "head_minishell.h"

static char	*ft_dol_helper(char *key, t_env *env, char *rez)
{
	t_env	*tmp;

	tmp = env;
	while (tmp && ft_strcmp(tmp->key, key))
		tmp = tmp->next;
	free(key), key = NULL;
	if (tmp)
	{
		rez = ft_strjoin_m(rez, tmp->val, 1);
	}
	return (rez);
}

static char	*ft_dol_exeption(t_data *data, char *str, int *i, char *rez)
{
	rez = ft_pars_helper(rez);
	if (str[*i + 1] == '-')
	{
		*i = *i + 2;
		return (ft_strjoin_m(rez, ft_strndup("_params_", 6), 3));
	}
	else if (str[*i + 1] == '?')
	{
		*i = *i + 2;
		return (ft_strjoin_m(rez, ft_itoa(data->ret_val), 3));
	}
	else if (str[*i + 1] == '0')
	{
		*i = *i + 2;
		rez = ft_dol_helper(ft_strdup("SHELL"), data->beg_env, rez);
		return (rez);
	}
	else if (str[*i + 1] == '$')
	{
		*i = *i + 2;
		return (ft_strjoin_m(rez, PID_EXEP, 1));
	}
	*i = *i + 2;
	return (ft_strjoin_m(rez, "0", 1));
}

static int	ft_dollar_chek(char *str, int *i, char **rez)
{
	if (str[*i + 1] != '_' && !ft_isalpha(str[*i + 1])
		&& !ft_isdigit(str[*i + 1]))
	{
		*rez = ft_strjoin_m(*rez, "$", 1);
		*i = *i + 1;
		return (1);
	}
	if (ft_ch_for_coinc(str[*i + 1], "123456789*@="))
	{
		*i = *i + 2;
		return (1);
	}
	return (0);
}

/*
**	@brief	Handles $ substitutes the value from env if it exist
**	@return	*char 	string rez with value
*/
char	*ft_dollar(t_data *data, char *str, int *i, char *rez)
{
	int		j;
	char	*key;

	if (ft_ch_for_coinc(str[*i + 1], "#0$-?"))
		return (ft_dol_exeption(data, str, i, rez));
	if (ft_dollar_chek(str, i, &rez))
		return (rez);
	j = *i + 1;
	while (str[j] && (str[j] == '_' || ft_isalnum(str[j])))
		j++;
	key = ft_strndup(&str[*i + 1], j - *i - 1);
	*i = j;
	rez = ft_dol_helper(key, data->beg_env, rez);
	return (rez);
}

char	*ft_normal(char *str, int *i, char *rez, char *stop)
{
	int	j;

	j = *i;
	while (str[j] && !ft_ch_for_coinc(str[j], stop))
		j++;
	if (*i != j)
		rez = ft_strjoin_m(rez, ft_strndup(&str[*i], j - *i), 3);
	*i = j;
	return (rez);
}
