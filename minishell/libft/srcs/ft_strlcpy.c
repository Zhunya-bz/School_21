#include "libft.h"

/*
**	@brief	copy source string to dest string, not more than dstsize - 1.
**			than null terminate dest.
**	
**	@param	dst		pointer to string
**	@param	src		pointer to string
**	@param	dstsize		count bytes to copy + 1 for null terminate
**	@return	size_t	lenght src string
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
