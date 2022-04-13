#include "libft.h"

/*
**	@brief	allocates memory (n bytes) and copy first n
**			chars string to this memory
**	
**	@param	src		pointer to string
**	@param	n		bytes for copy
**	@return	char*	pointer to new string or NULL
*/
char	*ft_strndup(const char *src, size_t n)
{
	char	*temp;
	size_t	kol;
	size_t	i;

	if (!src)
		return (NULL);
	kol = ft_strlen(src) + 1;
	if (kol < n)
	{
		temp = malloc(sizeof(char) * kol);
		n = kol;
	}
	else
		temp = malloc(sizeof(char) * (n + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
		temp[i] = src[i], i++;
	temp[i] = 0;
	return (temp);
}
