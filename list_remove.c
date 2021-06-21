/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_remove.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 12:43:00 by akant         #+#    #+#                 */
/*   Updated: 2021/06/15 13:54:12 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_middle_node(t_node *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
}

void	remove_not_first(t_dlist *list, int a)
{
	t_node	*temp;

	temp = list->first->next;
	while (temp)
	{
		if (temp->content == a)
		{
			if (temp == list->last)
			{
				temp->prev->next = NULL;
				list->last = temp->prev;
				free(temp);
			}
			else
				remove_middle_node(temp);
			return ;
		}
		temp = temp->next;
	}
}

void	remove_from_list(t_dlist *list, int a)
{
	t_node	*temp;

	if (list->first->content == a)
	{
		if (list->last->content == a)
		{
			free(list->first);
			list->first = NULL;
			list->last = NULL;
			list->nodes = 0;
		}
		else
		{
			temp = list->first;
			temp->next->prev = NULL;
			list->first = temp->next;
			free(temp);
		}
	}
	else
		remove_not_first(list, a);
}
