#include "push_swap.h"

t_dlist	*list_init(void)
{
	t_dlist *list;

	list = malloc(sizeof(t_dlist));
	if (!list)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	list->nodes = 0;
	return (list);
}

t_node	*new_node(int x)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = x;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	list_push(t_dlist *list, t_node *node)
{
	if (!list->first)
	{
		list->last = node;
		list->first = node;
	}
	else
	{
		list->first->prev = node;
		node->next = list->first;
		list->first = node;
	}
	list->nodes++;
}

t_node	*list_pop(t_dlist *list)
{
	t_node *temp;

	if (list->first && list->first == list->last)
	{
		temp = list->first;
		list->first = NULL;
		list->last = NULL;
		list->nodes--;
		return (temp);
	}
	if (list->first)
	{
		temp = list->first;
		list->first = list->first->next;
		list->first->prev = NULL;
		temp->next = NULL;
		list->nodes--;
		return (temp);
	}
	return (NULL);
}

void	print_list(t_dlist *list)
{
	t_node *temp;

	temp = list->first;
	while (temp)
	{
		printf("List: %d\n", temp->content);
		temp = temp->next;
	}
}
