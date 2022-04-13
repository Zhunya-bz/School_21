#include "libft.h"

/*
**	@brief	adds new element to the end of the list
**	
**	@param	lst		pointer to list
**	@param	new		pointer to new element
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_end;

	if (lst)
	{
		if (*lst)
		{
			lst_end = ft_lstlast(*lst);
			lst_end->next = new;
		}
		else
			*lst = new;
	}
}
