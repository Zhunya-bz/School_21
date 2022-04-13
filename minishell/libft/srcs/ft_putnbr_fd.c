#include "libft.h"

/*
**	@brief	write integer to file descriptor
**	
**	@param	n		integer
**	@param	fd		file descriptor
*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(56, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd(45, fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n / 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
}
