#include "libftprintf.h"
#include "libft/libft.h"

static void	posit_nbr_p(t_par_list *param, int len_nb)
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
		param->c_space = param->c_width - len_nb - 2;
		param->c_zero = 0;
	}
	if (param->c_space < 0)
		param->c_space = 0;
	param->len += param->c_space + len_nb + param->c_zero;
}

static void	print_pointer_minus(t_par_list *param, void *p)
{
	print_char(param->c_space, 32);
	if ((p == NULL) && (param->dot != 0 && !param->precision))
		ft_putstr_fd("0x", 1);
	else if ((p == NULL) && (param->dot != 0 && param->precision != 0))
	{
		ft_putstr_fd("0x0", 1);
		print_char(param->c_zero, '0');
	}
	else
	{
		ft_putstr_fd("0x", 1);
		print_char(param->c_zero, '0');
		ft_base_fd((unsigned long int)p, 1, 1, 0);
	}
}

static void	print_pointer_plus(t_par_list *param, void *p)
{
	if ((p == NULL) && (param->dot != 0 && !param->precision))
	{
		ft_putstr_fd("0x", 1);
		print_char(param->c_space, 32);
	}
	else if ((p == NULL) && (param->dot != 0 && param->precision != 0))
	{
		ft_putstr_fd("0x0", 1);
		print_char(param->c_zero, '0');
		print_char(param->c_space, 32);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		print_char(param->c_zero, '0');
		ft_base_fd((unsigned long int) p, 1, 1, 0);
		print_char(param->c_space, 32);
	}
}

void	write_pointer(t_par_list *param)
{
	void	*p;
	int		p_len;

	p = va_arg(param->arg, void *);
	p_len = ft_base_fd((unsigned long int)p, 1, 0, 0);
	if ((p == NULL) && (param->dot != 0 && !param->precision))
		posit_nbr_p(param, p_len + 1);
	else if ((p == NULL) && (param->dot != 0 && param->precision != 0
			&& param->c_width != 0))
		posit_nbr(param, p_len + 2);
	else
	{
		posit_nbr_p(param, p_len);
		param->len += 2;
	}
	if ((param->minus != 0))
	{
		print_pointer_plus(param, p);
	}
	else if (param->minus == 0)
		print_pointer_minus(param, p);
}
