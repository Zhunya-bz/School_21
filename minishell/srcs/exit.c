#include "head_minishell.h"

static void	help_exit(t_cmd *cmd, char *str, int val)
{
	cmd->data->ret_val = val;
	ft_pr_error(str, 1, 0, 6);
}

static int	ft_atoi_ret(const char *str, t_cmd *cmd)
{
	int					neg;
	unsigned long long	res;

	neg = 1;
	res = 0;
	while (*str && (*str == 32 || (*str > 8 && *str < 14)))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9' && res <= FT_ATOI_MN)
		res = res * 10 + (*str - 48), str++;
	if ((res >= ATOI_LL && neg == 1) || (res > ATOI_LL && neg == -1))
	{
		help_exit(cmd, "numeric argument required", 255);
		ft_free_data(cmd->data), exit(cmd->data->ret_val);
	}
	return ((int)res * neg);
}

int	ft_exit(t_cmd *cmd, size_t j)
{
	if (cmd->tot_arg >= 3)
	{
		help_exit(cmd, "too many arguments", 1);
		return (cmd->data->ret_val);
	}
	ft_redirects(cmd, 1);
	if (cmd->tot_arg > 1)
	{
		if (cmd->arg[1][j] == '-')
			j++;
		while (ft_isdigit(cmd->arg[1][j]))
			j++;
		cmd->data->ret_val = ft_atoi_ret(cmd->arg[1], cmd);
		if (j != ft_strlen(cmd->arg[1]))
			help_exit(cmd, "numeric argument required", 255);
		else
			ft_putendl_fd("exit", 2);
		ft_free_data(cmd->data), exit(cmd->data->ret_val);
	}
	else
	{
		ft_putendl_fd("exit", 2);
		ft_free_data(cmd->data), exit(cmd->data->ret_val);
	}
}
