/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 14:00:24 by akant         #+#    #+#                 */
/*   Updated: 2021/06/17 14:16:03 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;

	if (!lst || !f)
		return (NULL);
	newlist = ft_lstnew(f(lst->content));
	if (!newlist)
		return (NULL);
	lst = lst->next;
	newnode = newlist;
	while (lst)
	{
		newnode->next = ft_lstnew(f(lst->content));
		if (!newnode->next)
		{
			ft_lstclear(&newnode->next, del);
			return (NULL);
		}
		newnode = newnode->next;
		lst = lst->next;
	}
	return (newlist);
}
