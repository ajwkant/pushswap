#include "push_swap.h"

void	then_push(t_dlist *a, t_dlist *b, int num)
{
	rotate_b_correctly(b, num);
	push_list(a, b);
	write(1, "pb\n", 3);
	if (b->first->next && b->first->next->content > b->first->content)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
}

void	rotate_and_write(t_dlist *a, t_dlist *b, int num)
{
	rotate(a);
	if (b->first && num < b->first->content
		&& b->first->content > b->last->content)
	{
		rotate(b);
		write(1, "rr\n", 3);
	}
	else
		write(1, "ra\n", 3);
}

void	rev_rotate_and_write(t_dlist *a, t_dlist *b, int num)
{
	rev_rotate(a);
	if (b->first && num > b->last->content
		&& b->first->content < b->last->content)
	{
		rev_rotate(b);
		write(1, "rrr\n", 4);
	}
	else
		write(1, "rra\n", 4);
}

void	rotate_before_push(t_dlist *a, t_dlist *b, int pos, int num)
{
	while (pos)
	{
		if (pos > 0)
		{
			rotate_and_write(a, b, num);
			pos--;
		}
		else
		{
			rev_rotate_and_write(a, b, num);
			pos++;
		}
	}
}

void	chunk_sort(t_dlist *a, t_dlist *b, t_tree **tree, int chunksize)
{
	t_dlist	*chunk;
	int		direction;
	int		cheapest_pos;
	int		cheapest_num;

	chunk = find_chunk(tree, chunksize);
	if (!chunk)
	{
		clear_stacklist(a);
		free_list_tree(*tree, b, 1);
	}
	while (chunk->nodes)
	{
		direction = find_cheapest_direction(a, chunk);
		cheapest_pos = 0;
		cheapest_num = find_first_num(a, chunk, direction, &cheapest_pos);
		remove_from_list(chunk, cheapest_num);
		rotate_before_push(a, b, cheapest_pos, cheapest_num);
		then_push(a, b, cheapest_num);
	}
	free(chunk);
}
