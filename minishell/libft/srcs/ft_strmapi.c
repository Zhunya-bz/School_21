#include "libft.h"

/*
**	@brief	create copy of string,
**			and apply function f to each element new string
**	
**	@param	s		pointer to string
**	@param	f		function, return char
**	@return	char*	new string
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	num;
	size_t	i;
	char	*rez;

	if (!s)
		return (NULL);
	num = ft_strlen(s);
	rez = malloc(sizeof(char) * (num + 1));
	if (!rez)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rez[i] = f(i, s[i]);
		i++;
	}
	rez[i] = 0;
	return (rez);
}
