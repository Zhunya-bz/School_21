#include "libftprintf.h"
#include "libft/libft.h"

int	ft_base_fd(unsigned long int n, int fd, int flag, int reg)
{
	char	arr[17];
	int		i;
	char	*s;

	if (reg == 0)
		s = "0123456789abcdef";
	else if (reg == 1)
		s = "0123456789ABCDEF";
	i = 0;
	if ((n == 0) && (flag == 1))
		ft_putchar_fd('0', fd);
	else if ((n == 0) && (flag == 0))
		return (1);
	while (n != 0)
	{
		arr[i++] = s[n % 16];
		n = n / 16;
	}
	arr[i] = '\0';
	if (flag == 1)
		while (--i >= 0)
			write(fd, &arr[i], 1);
	return (ft_strlen(arr));
}

static void	print_unsig_int_flag_base(t_par_list *param, unsigned int ui, int
reg)
{
	if ((param->minus != 0))
	{
		print_char(param->c_zero, '0');
		ft_base_fd(ui, 1, 1, reg);
		print_char(param->c_space, 32);
	}
	else if (param->minus == 0)
	{
		print_char(param->c_space, 32);
		print_char(param->c_zero, '0');
		ft_base_fd(ui, 1, 1, reg);
	}
}

void	write_unsig_int_base(t_par_list *param, int reg)
{
	unsigned int	x;
	int				len_nb;

	x = va_arg(param->arg, unsigned int);
	len_nb = len_number(x, 0, param);
	if (len_nb < 0)
		return ;
	len_nb = ft_base_fd(x, 1, 0, reg);
	posit_nbr(param, len_nb);
	print_unsig_int_flag_base(param, x, reg);
}
