#include "push_swap.h"

void	clear_stacklist(t_dlist *list)
{
	t_node *node;

	if (list)
	{
		if (list->first)
		{
			node = list->first->next;
			while (node)
			{
				free(list->first);
				list->first = node;
				node = node->next;
			}
			free(list->first);
		}
		free(list);
	}
}

int		check_order(t_dlist *list)
{
	t_node	*current;
	int		prev;

	if (!list || !list->first)
		return (-1);
	prev = list->first->content;
	current = list->first->next;
	while (current)
	{
		if (current->content >= prev)
			return (0);
		current = current->next;
	}
	return (1);
}
