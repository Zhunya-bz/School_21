#include "libft.h"

/*
**	@brief	create new list element
**	
**	@param	val		element content
**	@return	t_list*	pointer to new element or NULL
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
