#include "libft.h"

/*
**	@brief lexicographically compare two strings.
**	@param	s1		pointer to string
**	@param	s2		pointer to string
**	@return	int	zero if strings are identical, 
**		else difference between two elements (unsinged char)
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
