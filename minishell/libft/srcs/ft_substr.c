#include "libft.h"

/*
**	@brief	allocates and returns a substring from the string.
**			The substring begins at index ’start’ and is of maximum size ’len’
**	
**	@param	s		pointer to string
**	@param	start	index start of substring
**	@param	len		index end of substring
**	@return	char*	pointer to new string or NULL if allocation fail
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*rez;
	unsigned int	i;

	if (!s)
		return (NULL);
	rez = malloc(sizeof(char) * len + 1);
	if (!rez)
		return (NULL);
	rez[0] = 0;
	if (ft_strlen(s) <= start)
		return (rez);
	i = 0;
	while (start + i < start + len)
	{
		rez[i] = s[start + i];
		i++;
	}
	rez[i] = 0;
	return (rez);
}
