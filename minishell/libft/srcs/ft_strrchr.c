#include "libft.h"

/*
**	@brief	locates the last occurrence of c in the string s
**	
**	@param	s		pointer to string
**	@param	c		character to search
**	@return	char*	pointer to the found position c or NULL
*/
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}
