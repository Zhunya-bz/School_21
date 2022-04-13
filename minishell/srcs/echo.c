#include "head_minishell.h"

static int	ft_skip_redir(char *str, int i)
{
	i++;
	if (ft_ch_for_coinc(str[i], "><"))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))
		i++;
	return (i);
}

char	*ft_proc_echo(t_data *data, char *str, int *i, char *rez)
{
	while (str && str[*i] && str[*i] == ' ')
		*i = *i + 1;
	while (str && str[*i] && str[*i] != ' ')
	{
		if (str[*i] == '\'')
			rez = ft_quotes(data, str, i, rez);
		else if (str[*i] == '$')
			rez = ft_dollar(data, str, i, rez);
		else if (str[*i] == '\"')
			rez = ft_double_quotes(data, str, i, rez);
		else if (str[*i] == '\\')
		{
			rez = ft_strjoin_m(rez, ft_strndup(&str[*i + 1], 1), 3);
			*i = *i + 2;
		}
		else if (str[*i] && ft_ch_for_coinc(str[*i], "><"))
			*i = ft_skip_redir(str, *i);
		else
			rez = ft_normal(str, i, rez, "> <\\'\"$");
	}
	return (rez);
}

int	ft_echo_arg_check(char *str)
{
	int	i;

	i = 0;
	if (str && str[i] == '-')
	{
		i++;
		while (str[i] == 'n')
			i++;
		if (!str[i] && i >= 2)
			return (0);
	}
	return (1);
}

void	ft_predv_obrab(t_cmd *cmd)
{
	char	*rez;
	int		i;
	int		j;

	if (cmd->fd_inf > 0)
		close(cmd->fd_inf), cmd->fd_inf = -1;
	rez = NULL;
	ft_free_split(cmd->arg), cmd->cmd = NULL;
	cmd->arg = malloc(sizeof(char *) * PWD_LEN);
	cmd->cmd = cmd->arg[0];
	j = 0;
	i = 0;
	while (cmd->dino[i])
	{
		rez = ft_proc_echo(cmd->data, cmd->dino, &i, rez);
		if (rez)
			cmd->arg[j] = rez, j++;
		rez = NULL;
		while (cmd->dino[i] && cmd->dino[i] == ' ')
			i++;
	}
	cmd->arg[j] = NULL;
	cmd->cmd = cmd->arg[0];
}
