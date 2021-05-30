#include "push_swap.h"

void	write_and_count(char *string, int len)
{
	write(1, string, len);
	g_instructions++;
	if (len > 4)
		g_instructions++;
}

int		direction(int nodes, int pos)
{
	if (pos > nodes / 2)
		return (pos - nodes);
	else
		return (pos);
}

void	rotate_list_x(t_dlist *a, int x)
{
	while (x > 0)
	{
		write_and_count("ra\n", 3);
		rotate(a);
		x--;
	}
	while (x < 0)
	{
		write_and_count("rra\n", 4);
		rev_rotate(a);
		x++;
	}
}

void	b_to_a(t_dlist *a, t_dlist *b)
{
	while (b->first)
	{
		write_and_count("pa\n", 3);
		push_list(b, a);
	}
}

int		algorithmic_sort(t_dlist *a, t_dlist *b, t_tree **tree)
{
	t_tree	*node;
	int		dir;

	while (a->nodes)
	{
		node = tree_get_smallest(tree);
		dir = direction(a->nodes, find_pos(a, node->content));
		rotate_list_x(a, dir);
		push_list(a, b);
		write_and_count("pb\n", 3);
	}
	b_to_a(a, b);
	return (1);
}

int	chunk_sort(t_dlist *a, t_dlist *b) // nieuwe poging om het met chunks te doen
{
	// int	total_to_be_sorted;
	// int	num_per_box;
	// int	boxes;
	// int i;

	// total_to_be_sorted = a->nodes;
	// // Magic for selecting amount of boxes
	// boxes = 5; // Temporary number
	// i = 0;
	// while (i < boxes)
	// {
	// 	insertion_sort(a, b, num_per_box * i); // To be looked at
	// }

	find_chunk
}
