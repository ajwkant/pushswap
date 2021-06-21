#include "push_swap.h"

void	b_to_a(t_dlist *a, t_dlist *b)
{
	while (b->first)
	{
		write(1, "pa\n", 3);
		push_list(b, a);
	}
}

int	algorithmic_sort(t_dlist *a, t_dlist *b, t_tree **tree)
{
	int	nodes;

	nodes = (a->nodes + 100) / 14;
	while (a->nodes)
		chunk_sort(a, b, tree, nodes);
	b_to_a(a, b);
	while (a->first->content > a->last->content)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	while (a->first->content > a->first->next->content)
	{
		rev_rotate(a);
		write(1, "rra\n", 4);
	}
	return (1);
}
