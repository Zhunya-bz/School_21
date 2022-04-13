#include "libft.h"

/*
**	@brief	deletes and frees the given element and every successor of that element
**	
**	@param	lst		the addres of a pointer to the list
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buf;

	if (lst && del)
	{
		while (*lst)
		{
			buf = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = buf;
		}
	}
}
