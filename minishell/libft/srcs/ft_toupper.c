#include "libft.h"

/*
**	@brief		convert char to uppercase if it's lowercase
**	
**	@param	c		character
**	@return	int		character
*/
int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}
