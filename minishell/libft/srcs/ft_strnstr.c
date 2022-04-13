#include "libft.h"

/*
**	@brief	locates the first occurrence string 'needle' in string 'haystack'.
**			searches in a substring 'haystack' of length at most 'len'
**	
**	@param	has			pointer to string
**	@param	ned			pointer to string
**	@param	len			lenght substring
**	@return	char*	pointer to the beginning of found string. NULL if not found
*/
char	*ft_strnstr(const char *has, const char *ned, size_t len)
{
	size_t	i;
	size_t	j;

	if (ned[0] == 0)
		return ((char *)has);
	i = 0;
	while (has[i] && i < len)
	{
		j = 0;
		while (has[i + j] && ned[j] && has[i + j] == ned[j] && (i + j) < len)
			j++;
		if (!ned[j])
			return (&((char *)has)[i]);
		i++;
	}
	return (NULL);
}
