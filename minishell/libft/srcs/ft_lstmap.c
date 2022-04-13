#include "libft.h"

/*
**	@brief	create new list, where each content is result successive applied
**			of the function to content element of old list
**	
**	@param	lst		pointer to the old list
**	@param	f		function for create new content
**	@return	t_list*	pointer to new list or NULL
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*buf;
	t_list	*start;
	t_list	*newl;

	if (!lst)
		return (NULL);
	buf = lst;
	start = ft_lstnew(f(buf->content));
	if (!start)
		return (NULL);
	buf = buf->next;
	while (buf)
	{
		newl = ft_lstnew(f(buf->content));
		if (!newl)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, newl);
		buf = buf->next;
	}
	return (start);
}
