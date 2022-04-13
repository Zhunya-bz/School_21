#include "libftprintf.h"
#include "libft/libft.h"

void	zero_fil(t_par_list *param)
{
	param->width = 0;
	param->zero = 0;
	param->dot = 0;
	param->star_w = 0;
	param->star_p = 0;
	param->minus = 0;
	param->c_space = 0;
	param->precision = 0;
	param->c_zero = 0;
	param->c_width = 0;
}

int	len_number(long n, int len_nb, t_par_list *param)
{
	if (n == 0 && param->dot != 0 && param->precision == 0)
	{
		param->c_space = param->c_width;
		param->len += param->c_space;
		while (param->c_space-- > 0)
			ft_putchar_fd(' ', 1);
		return (-1);
	}
	if (n == 0)
		len_nb++;
	while (n != 0)
	{
		n = n / 10;
		len_nb++;
	}
	return (len_nb);
}

void	print_char(int i, char c)
{
	while (i-- > 0)
		ft_putchar_fd(c, 1);
}

void	check_star(t_par_list *param)
{
	if (param->star_w != 0)
	{
		param->c_width = va_arg(param->arg, int);
		param->width = 1;
		if (param->c_width < 0)
		{
			param->c_width = -param->c_width;
			param->minus = 1;
			param->zero = 0;
		}
	}
	if (param->star_p != 0)
	{
		param->precision = va_arg(param->arg, int);
		if (param->precision < 0)
		{
			param->precision = 0;
			param->dot = 0;
		}
	}
}
