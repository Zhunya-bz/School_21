#include "libftprintf.h"
#include "libft/libft.h"

static void	posit_nbr_per(t_par_list *param, int len_nb)
{
	if (param->dot != 0 && !param->precision)
		param->c_space = param->c_width - len_nb;
	else if (param->zero != 0)
		param->c_zero = param->c_width - len_nb;
	else if (param->zero == 0)
		param->c_space = param->c_width - len_nb;
	if (param->c_zero < 0)
	{
		param->c_space = param->c_width - len_nb;
		param->c_zero = 0;
	}
	if (param->c_space < 0)
		param->c_space = 0;
	param->len += param->c_space + len_nb + param->c_zero;
}

static void	write_percent(t_par_list *param)
{
	posit_nbr_per(param, 1);
	if ((param->minus != 0))
	{
		print_char(param->c_zero, '0');
		ft_putchar_fd('%', 1);
		print_char(param->c_space, 32);
	}
	else if (param->minus == 0)
	{
		print_char(param->c_space, 32);
		print_char(param->c_zero, '0');
		ft_putchar_fd('%', 1);
	}
}

static int	check_type(const char *format, t_par_list *param, int i)
{
	if (format[i] == 's')
		write_string(param);
	if ((format[i] == 'd') || (format[i] == 'i'))
		write_d_width_prec(param);
	if (format[i] == 'c')
		write_char(param);
	if (format[i] == 'p')
		write_pointer(param);
	if (format[i] == 'u')
		write_unsig_int(param);
	if (format[i] == 'x')
		write_unsig_int_base(param, 0);
	if (format[i] == 'X')
		write_unsig_int_base(param, 1);
	if (format[i] == '%')
		write_percent(param);
	return (i);
}

static void	general_func(const char *format, t_par_list *param)
{
	int		i;

	i = 0;
	while (format[i] != '\0')
	{
		while ((format[i]) && (format[i++] != '%'))
		{
			ft_putchar_fd(format[i - 1], 1);
			param->len++;
		}
		if (!format[i])
			break ;
		if (format[i - 1] == '%')
		{
			zero_fil(param);
			i = go_flags_al(format, param, i);
			if (!format[i])
				break ;
			check_star(param);
			i = check_type(format, param, i);
		}
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	t_par_list	param;

	va_start(param.arg, format);
	param.len = 0;
	general_func(format, &param);
	va_end(param.arg);
	return (param.len);
}
