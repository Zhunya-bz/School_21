#include "libft.h"

/*
**	@brief	fills a byte string with a byte value
**	
**	@param	b		pointer to string b
**	@param	c		filler
**	@param	len		count bytes to fill
**	@return	void*	original pointer to string b
*/
void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		((unsigned char *)b)[len] = (unsigned char)c;
	}
	return (b);
}
