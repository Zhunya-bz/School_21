#include "libft.h"

/*
**	@brief	adds string src to string dst, 
*			where finish string lenght no more than dstsize
**	
**	@param	dst			pointer to string
**	@param	src			pointer to string
**	@param	dstsize		length finish string  (with '\0')
**	@return	size_t		expected length of the resulting string (dst + src)
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (dstsize > 0 && len_dst < (dstsize - 1))
	{
		while (src[i] && (len_dst + i) < (dstsize - 1))
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
	}
	if (len_dst >= dstsize)
		len_dst = dstsize;
	return (len_dst + len_src);
}
