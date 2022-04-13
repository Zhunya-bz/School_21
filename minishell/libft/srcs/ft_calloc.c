#include "libft.h"

/*
**	@brief	allocations memory like malloc, but uses count object multiply by 
**			size objects and then fills space zeros
**	
**	@param	count		count objects
**	@param	size		size one object in bytes
**	@return	void*	pointer to allocation memory or NULL if allocation fail
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*rez;

	rez = malloc(count * size);
	if (!rez)
		return (NULL);
	ft_bzero(rez, (count * size));
	return (rez);
}
