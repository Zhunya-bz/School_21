#include "libft.h"

/*
**	@brief	copies n bytes from memory area src to memory area dst.
**			If dst and src overlap, behavior is undefined.
**	
**	@param	dst		pointer to dist
**	@param	src		pointer to source
**	@param	n		count bytes for copy
**	@return	void*	original pointer to dist
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (n == 0 || dst == src)
		return (dst);
	while (n--)
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	return ((void *)dst);
}
