#include "libftprintf.h"
#include "libft/libft.h"

static int	go_flags(const char *format, t_par_list *param, int i)
{
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
		{
			param->minus = 1;
			param->zero = 0;
			i++;
		}
		else if (format[i] == '0' && !param->minus)
		{
			param->zero = 1;
			i++;
		}
		else if (format[i] == '0')
			i++;
		else
		{
			i++;
			break ;
		}
	}
	return (i);
}

static int	go_width(const char *format, t_par_list *param, int i)
{
	while (ft_isdigit(format[i]) || format[i] == '*')
	{
		if (format[i] == '*')
		{
			param->star_w = 1;
			i++;
		}
		while (ft_isdigit(format[i]) && format[i])
		{
			param->c_width = param->c_width * 10 + format[i] - '0';
			i++;
		}
		param->width = 1;
	}
	return (i);
}

static int	go_prec(const char *format, t_par_list *param, int i)
{
	if (format[i] == '.' && format[i])
	{
		param->dot = 1;
		i++;
		if (format[i] == '*')
		{
			param->star_p = 1;
			i++;
		}
		if (format[i] == '-')
		{
			param->precision = 0;
			param->dot = 0;
			param->c_width = 0;
			i++;
		}
		while (format[i] && ft_isdigit(format[i]))
		{
			param->precision = param->precision * 10 + format[i] - '0';
			i++;
		}
	}
	return (i);
}

int	go_flags_al(const char *format, t_par_list *param, int i)
{
	i = go_flags(format, param, i);
	i = go_width(format, param, i);
	i = go_prec(format, param, i);
	return (i);
}
