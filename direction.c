/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   direction.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 12:35:17 by akant         #+#    #+#                 */
/*   Updated: 2021/06/17 15:28:27 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest_direction(t_dlist *a, t_dlist *chunk)
{
	int		cost_rotate;
	int		cost_rev_rotate;
	int		pos;
	t_node	*temp;

	cost_rotate = 0;
	cost_rev_rotate = 0;
	temp = chunk->first;
	while (temp)
	{
		pos = find_pos(a, temp->content);
		cost_rotate += pos;
		cost_rev_rotate += a->nodes - pos;
		temp = temp->next;
	}
	if (cost_rotate <= cost_rev_rotate)
		return (1);
	return (-1);
}

t_node	*loop_through_chunk(t_dlist *chunk, t_node *node)
{
	t_node	*chunk_node;

	chunk_node = chunk->first;
	while (chunk_node)
	{
		if (chunk_node->content == node->content)
			return (chunk_node);
		chunk_node = chunk_node->next;
	}
	return (NULL);
}

int	find_first_num(t_dlist *a, t_dlist *chunk,
		int direction, int *cheapest_pos)
{
	t_node	*node;
	t_node	*chunk_node;

	node = a->first;
	while (1)
	{
		chunk_node = loop_through_chunk(chunk, node);
		if (chunk_node)
			return (chunk_node->content);
		if (direction == 1)
			node = node->next;
		else if (node->prev)
			node = node->prev;
		else
			node = a->last;
		*cheapest_pos += 1;
		if (direction == -1)
			*cheapest_pos -= 2;
	}
}

void	rotate_b_correctly(t_dlist *b, int num)
{
	while (b->first)
	{
		if (num < b->first->content && b->first->next
			&& b->first->content > b->first->next->content)
		{
			rotate(b);
			write(1, "rb\n", 3);
		}
		else if (num > b->first->content && b->first->content < b->last->content
			&& num > b->last->content)
		{
			rev_rotate(b);
			write(1, "rrb\n", 4);
		}
		else
			return ;
	}
}
