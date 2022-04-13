#include "libft.h"

/*
**	@brief	locates the first occurrence of c in the string s
**	
**	@param	s		pointer to string
**	@param	c		character to search
**	@return	char*	pointer to the found position c or NULL
*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == c)
		return (&((char *)s)[i]);
	return (NULL);
}
