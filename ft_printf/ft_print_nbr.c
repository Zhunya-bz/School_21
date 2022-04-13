#include "libftprintf.h"
#include "libft/libft.h"

void	negat_nbr(t_par_list *param, int len_nb)
{
	if ((param->dot != 0 && !param->precision))
	{
		param->c_space = param->c_width - len_nb - 1;
		param->c_zero = 0;
	}
	else if (param->zero != 0 && param->precision == 0)
	{
		param->c_zero = param->c_width - len_nb - 1;
		param->c_space = 0;
	}
	else
	{
		param->c_space = param->c_width - param->precision - 1;
		param->c_zero = param->precision - len_nb;
	}
	if (param->c_zero < 0)
	{
		param->c_space = param->c_width - len_nb - 1;
		param->c_zero = 0;
	}
	if (param->c_space < 0)
		param->c_space = 0;
	param->len += param->c_space + len_nb + param->c_zero + 1;
}

void	posit_nbr(t_par_list *param, int len_nb)
{
	if ((param->dot != 0 && !param->precision))
	{
		param->c_space = param->c_width - len_nb;
		param->c_zero = 0;
	}
	else if (param->zero != 0 && param->precision == 0)
	{
		param->c_zero = param->c_width - len_nb;
		param->c_space = 0;
	}
	else
	{
		param->c_space = param->c_width - param->precision;
		param->c_zero = param->precision - len_nb;
	}
	if (param->c_zero < 0)
	{
		param->c_space = param->c_width - len_nb;
		param->c_zero = 0;
	}
	if (param->c_space < 0)
		param->c_space = 0;
	param->len += param->c_space + len_nb + param->c_zero;
}

void	write_posit_nbr(t_par_list *param, int nbr)
{
	if ((param->minus != 0))
	{
		print_char(param->c_zero, '0');
		ft_putnbr_fd(nbr, 1);
		print_char(param->c_space, 32);
	}
	else if (param->minus == 0)
	{
		print_char(param->c_space, 32);
		print_char(param->c_zero, '0');
		ft_putnbr_fd(nbr, 1);
	}
}

void	write_negat_nbr(t_par_list *param, int nbr)
{
	if (param->minus != 0)
	{
		if (nbr == -2147483648)
			ft_putnbr_fd(nbr, 1);
		else
		{
			ft_putchar_fd('-', 1);
			print_char(param->c_zero, '0');
			ft_putnbr_fd(-nbr, 1);
			print_char(param->c_space, 32);
		}
	}
	else if (param->minus == 0)
	{
		print_char(param->c_space, 32);
		if (nbr == -2147483648)
			ft_putnbr_fd(nbr, 1);
		else
		{
			ft_putchar_fd('-', 1);
			print_char(param->c_zero, '0');
			ft_putnbr_fd(-nbr, 1);
		}
	}
}

void	write_d_width_prec(t_par_list *param)
{
	int	nbr;
	int	len_nb;

	nbr = va_arg(param->arg, int);
	len_nb = len_number(nbr, 0, param);
	if (len_nb < 0)
		return ;
	if (nbr < 0)
	{
		negat_nbr(param, len_nb);
		write_negat_nbr(param, nbr);
	}
	else
	{
		posit_nbr(param, len_nb);
		write_posit_nbr(param, nbr);
	}
}
