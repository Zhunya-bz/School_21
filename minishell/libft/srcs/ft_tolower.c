#include "libft.h"

/*
**	@brief	convert char to lowercase if it's uppercase
**	
**	@param	c		character
**	@return	int		character
*/
int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}
