/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 12:43:00 by akant         #+#    #+#                 */
/*   Updated: 2021/06/15 14:26:26 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_dlist *list)
{
	t_node	*node1;
	t_node	*node2;

	if (list && list->first && list->first->next)
	{
		node1 = list_pop(list);
		node2 = list_pop(list);
		list_push(list, node1);
		list_push(list, node2);
	}
}

void	push_list(t_dlist *a, t_dlist *b)
{
	t_node	*node;

	node = list_pop(a);
	if (!node)
		return ;
	list_push(b, node);
}

void	rotate(t_dlist *list)
{
	if (list && list->first && list->first->next)
	{
		list->first->prev = list->last;
		list->last->next = list->first;
		list->first->next->prev = NULL;
		list->first = list->first->next;
		list->last->next->next = NULL;
		list->last = list->last->next;
	}
}

void	rev_rotate(t_dlist *list)
{
	if (list && list->first && list->first->next)
	{
		list->last->next = list->first;
		list->first->prev = list->last;
		list->last->prev->next = NULL;
		list->last = list->last->prev;
		list->first->prev->prev = NULL;
		list->first = list->first->prev;
	}
}
