#include "libftprintf.h"
#include "libft/libft.h"

void	ft_putnbr_un_fd(unsigned int nb, int fd)
{
	char	arr[11];
	int		i;

	i = 0;
	if (nb == 0)
		ft_putchar_fd('0', fd);
	while (nb != 0)
	{
		arr[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	arr[i] = '\0';
	i--;
	while (i >= 0)
	{
		write(fd, &arr[i], 1);
		i--;
	}
}

static void	print_unsig_int_flag(t_par_list *param, unsigned int ui)
{
	if ((param->minus != 0))
	{
		print_char(param->c_zero, '0');
		ft_putnbr_un_fd(ui, 1);
		print_char(param->c_space, 32);
	}
	else if (param->minus == 0)
	{
		print_char(param->c_space, 32);
		print_char(param->c_zero, '0');
		ft_putnbr_un_fd(ui, 1);
	}
}

void	write_unsig_int(t_par_list *param)
{
	unsigned int	ui;
	int				len_nb;

	ui = va_arg(param->arg, unsigned int);
	len_nb = len_number(ui, 0, param);
	if (len_nb < 0)
		return ;
	posit_nbr(param, len_nb);
	print_unsig_int_flag(param, ui);
}
