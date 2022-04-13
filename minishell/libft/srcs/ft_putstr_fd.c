#include "libft.h"

/*
**	@brief	write string to the file descriptor
**	
**	@param	s		pointer to string
**	@param	fd		file desriptor
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}
