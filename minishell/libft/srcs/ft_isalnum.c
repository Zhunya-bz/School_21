#include "libft.h"

/*
**	@brief	tests for any character for which is alphabet or number
**	
**	@param	c	character
**	@return	int	0 if tests false, else 1
*/
int	ft_isalnum(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else if (c < 65 || c > 122)
		return (0);
	else if (c > 90 && c < 97)
		return (0);
	return (1);
}
