#include "push_swap.h"

int	swap(t_dlist *list) // kan sneller gemaakt worden door niet pop en push te gebruiken
{
	t_node *node1;
	t_node *node2;

	if (list && list->first && list->first->next)
	{
		node1 = list_pop(list);
		node2 = list_pop(list);
		list_push(list, node1);
		list_push(list, node2);
		return (1);
	}
	return (0);
}

int	push_a(t_dlist *a, t_dlist *b)
{
	t_node *node;

	node = list_pop(b);
	if (!node)
		return (0);
	list_push(a, node);
	a->nodes++;
	b->nodes--;
	return (1);
}

int	push_b(t_dlist *a, t_dlist *b)
{
	t_node *node;

	node = list_pop(a);
	if (!node)
		return (0);
	list_push(b, node);
	a->nodes--;
	b->nodes++;
	return (1);
}

int	rotate(t_dlist *list)
{
	if (list && list->first && list->first->next)
	{
		list->first->prev = list->last;
		list->last->next = list->first;
		list->first->next->prev = NULL;
		list->first = list->first->next;
		list->last->next->next = NULL;
		list->last = list->last->next;
		return (1);
	}
	return (0);
}

int	rev_rotate(t_dlist *list)
{
	if (list && list->first && list->first->next)
	{
		list->last->next = list->first;
		list->first->prev = list->last;
		list->last->prev->next = NULL;
		list->last = list->last->prev;
		list->first->prev->prev = NULL;
		list->first = list->first->prev;
		return (1);
	}
	return (0);
}
