#include "libft.h"

/*
**	@brief	checks a character is printable (between 32 and 126 included)
**	
**	@param	c		character
**	@return	int		0 if tests false, else 1
*/
int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}
