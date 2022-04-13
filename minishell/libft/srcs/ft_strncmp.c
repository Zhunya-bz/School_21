#include "libft.h"

/*
**	@brief	lexicographically compare two strings. Not more n characters
**	
**	@param	s1		pointer to string
**	@param	s2		pointer to string
**	@param	len		count bytes
**	@return	int	zero if strings are identical, 
**				else difference between two elements (unsinged char)
*/
int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
