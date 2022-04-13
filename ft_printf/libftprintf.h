#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

typedef struct s_par_list
{
	va_list	arg;
	int		minus;
	int		zero;
	int		star_w;
	int		star_p;
	int		width;
	int		dot;
	int		c_space;
	int		c_zero;
	int		c_width;
	int		precision;
	int		len;
}				t_par_list;

int		ft_printf(const char *format, ...);
int		go_flags_al(const char *format, t_par_list *param, int i);
void	negat_nbr(t_par_list *param, int len_nb);
void	posit_nbr(t_par_list *param, int len_nb);
void	write_posit_nbr(t_par_list *param, int nbr);
void	write_negat_nbr(t_par_list *param, int nbr);
void	write_d_width_prec(t_par_list *param);
void	zero_fil(t_par_list *param);
int		len_number(long n, int len_nb, t_par_list *param);
void	print_char(int fl, char c);
void	check_star(t_par_list *param);
void	write_string(t_par_list *param);
void	write_char(t_par_list *param);
void	write_unsig_int(t_par_list *param);
void	ft_putnbr_un_fd(unsigned int nb, int fd);
int		ft_base_fd(unsigned long int n, int fd, int flag, int reg);
void	write_unsig_int_base(t_par_list *param, int reg);
void	write_pointer(t_par_list *param);

#endif
