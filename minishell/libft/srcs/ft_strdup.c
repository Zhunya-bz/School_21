#include "libft.h"

/*
**	@brief	allocates memory and copy string to this memory
**	
**	@param	src		pointer to string
**	@return	char*	pointer to new string or NULL
*/
char	*ft_strdup(const char *src)
{
	char	*temp;
	size_t	kol;
	size_t	i;

	if (!src)
		return (NULL);
	kol = ft_strlen(src) + 1;
	temp = malloc(sizeof(char) * kol);
	if (!temp)
		return (NULL);
	i = 0;
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = src[i];
	return (temp);
}
