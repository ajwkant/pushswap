#include "push_swap.h"

void	insert_after_first(t_dlist *a, t_dlist *b)
{
	push_list(b, a);
	swap(a);
	write_and_count("pa\nsa\n", 6);
}

void	insert_after_second(t_dlist *a, t_dlist *b)
{
	rotate(a);
	push_list(b, a);
	swap(a);
	rev_rotate(a);
	write_and_count("ra\npa\nsa\nrra\n", 13);
}

void	insert_after_third(t_dlist *a, t_dlist *b)
{
	rev_rotate(a);
	push_list(b, a);
	// rotate(a);
	// rotate(a);
	// write_and_count("rra\npa\nra\nra\n", 13);
	write_and_count("rra\npa\n", 7);
}

void	rotate_a(t_dlist *a)
{
	rotate(a);
	write_and_count("ra\n", 3);
}

void	rev_rotate_a(t_dlist *a)
{
	rev_rotate(a);
	write_and_count("rra\n", 4);
}

void	rotate_correctly(t_dlist *a) // CONTENT
{
	if (a->first->content > a->first->next->content &&
		a->first->content > a->last->content)
		rotate_a(a);
	while (a->first->content < a->first->next->content &&
		a->first->content > a->last->content)
		rev_rotate_a(a);
}

int	sort_fifth(t_dlist *a, t_dlist *b)
{
	if (b->first->content > a->first->content &&
		b->first->content < a->first->next->content)
		insert_after_first(a, b);
	else if (b->first->content > a->first->next->content &&
		b->first->content < a->first->next->next->content)
		insert_after_second(a, b);
	else if (b->first->content > a->first->next->next->content &&
		b->first->content < a->last->content)
		insert_after_third(a, b);
	else
	{
		push_list(b, a);
		rotate(a);
		write_and_count("pa\nra\n", 6);
	}
	rotate_correctly(a);
	return (1);
}

int	sort_four_five(t_dlist *a, t_dlist *b)
{
	push_list(a, b);
	write_and_count("pb\n", 3);
	push_list(a, b);
	write_and_count("pb\n", 3);
	sort_three(a);
	// print_list(a);
	write_and_count("pa\n", 3);
	push_list(b, a);
	// print_list(a);
	if (a->first->content > a->first->next->content &&
		a->first->content < a->first->next->next->content)
	{
		write_and_count("sa\n", 3);
		swap(a);
	}
	else if (a->first->content < a->last->content &&
		a->first->content > a->first->next->next->content)
	{
		write_and_count("rra\nsa\n", 7);
		rev_rotate(a);
		swap(a);
	}
	if (b->first)
		return (sort_fifth(a, b));
	return (1);
}

// int	insertion_sort(t_dlist *a, t_dlist *b, int chunk_size)
// {
// 	int lowest;
// 	int i;

// 	lowest = a->first->content;
// 	i = a->nodes;
// 	while (i)
// 	{
// 		rotate(a);
// 		if (a->first < lowest)
// 			lowest = a->first;
// 		i--;
// 	}
// }

// int	chunk_sort(t_dlist *a, t_dlist *b)
// {
// 	int	total_to_be_sorted;
// 	int	num_per_box;
// 	int	boxes;
// 	int i;

// 	total_to_be_sorted = a->nodes;
// 	// Magic for selecting amount of boxes
// 	boxes = 5; // Temporary number
// 	i = 0;
// 	while (i < boxes)
// 	{
// 		insertion_sort(a, b, num_per_box * i); // To be looked at
// 	}
// }

int	sorting(t_dlist *a, t_dlist *b, t_tree **tree)
{
	if (a->nodes == 1)
		return (1);
	if (a->nodes == 2)
		return (sort_two(a));
	if (a->nodes == 3)
		return (sort_three(a));
	if (a->nodes > 3 && a->nodes <= 5)
		return (sort_four_five(a, b));
	if (a->nodes > 5)
		return (algorithmic_sort(a, b, tree));
	return (0);
}
