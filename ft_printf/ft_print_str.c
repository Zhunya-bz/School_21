#include "libftprintf.h"
#include "libft/libft.h"

static void	print_string_len(t_par_list *param, char *str, int len_str)
{
	int	i;

	i = 0;
	if (param->precision != 0)
	{
		while (i < param->precision && str[i])
		{
			ft_putchar_fd(str[i++], 1);
			param->len++;
		}
	}
	else if (!param->dot)
	{
		ft_putstr_fd(str, 1);
		param->len += len_str;
	}
}

static void	print_string_flag(t_par_list *param, char *str, int len_str)
{
	if ((param->minus != 0))
	{
		print_string_len(param, str, len_str);
		print_char(param->c_space, 32);
	}
	else if (param->minus == 0)
	{
		print_char(param->c_space, 32);
		print_string_len(param, str, len_str);
	}
}

void	write_string(t_par_list *param)
{
	char	*str;
	int		len_str;

	str = va_arg(param->arg, char *);
	if (!str)
		str = "(null)";
	len_str = ft_strlen(str);
	if (param->dot != 0 && !param->precision)
		param->c_space = param->c_width;
	else if ((param->precision != 0) && (len_str > param->precision))
		param->c_space = param->c_width - param->precision;
	else if (param->width != 0)
		param->c_space = param->c_width - len_str;
	if (param->c_space < 0)
		param->c_space = 0;
	param->len += param->c_space;
	print_string_flag(param, str, len_str);
}

void	write_char(t_par_list *param)
{
	char	ch;

	ch = (char)va_arg(param->arg, int);
	if (param->width != 0)
		param->c_space = param->c_width - 1;
	if (param->c_space < 0)
		param->c_space = 0;
	param->len += param->c_space;
	if ((param->minus != 0))
	{
		ft_putchar_fd(ch, 1);
		param->len++;
		print_char(param->c_space, 32);
	}
	else if (param->minus == 0)
	{
		print_char(param->c_space, 32);
		ft_putchar_fd(ch, 1);
		param->len++;
	}
}
