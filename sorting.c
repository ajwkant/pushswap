/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 14:24:35 by akant         #+#    #+#                 */
/*   Updated: 2021/06/17 14:37:25 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_correctly(t_dlist *a)
{
	if (a->first->content > a->first->next->content
		&& a->first->content > a->last->content)
		rotate_a(a);
	while (a->first->content < a->first->next->content
		&& a->first->content > a->last->content)
		rev_rotate_a(a);
}

void	sort_fifth(t_dlist *a, t_dlist *b)
{
	if ((b->first->content > a->first->content
			&& b->first->content < a->first->next->content)
		|| (b->first->content < a->first->content
			&& b->first->content < a->first->next->content
			&& a->first->content > a->first->next->content))
		insert_after_first(a, b);
	else if (b->first->content > a->first->next->content
		&& b->first->content < a->first->next->next->content)
		insert_after_second(a, b);
	else if (b->first->content > a->first->next->next->content
		&& b->first->content < a->last->content)
		insert_after_third(a, b);
	else
	{
		push_list(b, a);
		rotate(a);
		write(1, "pa\nra\n", 6);
	}
}

void	first_sort_first_three(t_dlist *a, t_dlist *b)
{
	push_list(a, b);
	write(1, "pb\n", 3);
	if (a->nodes != 3)
	{
		push_list(a, b);
		write(1, "pb\n", 3);
	}
	sort_three(a);
}

void	sort_four_five(t_dlist *a, t_dlist *b)
{
	first_sort_first_three(a, b);
	write(1, "pa\n", 3);
	push_list(b, a);
	if (a->first->content > a->first->next->content
		&& a->first->content < a->first->next->next->content)
	{
		write(1, "sa\n", 3);
		swap(a);
	}
	else if (a->first->content < a->last->content
		&& a->first->content > a->first->next->next->content)
	{
		write(1, "rra\nsa\n", 7);
		rev_rotate(a);
		swap(a);
	}
	if (b->first)
		sort_fifth(a, b);
	rotate_correctly(a);
}

void	sorting(t_dlist *a, t_dlist *b, t_tree **tree)
{
	if (a->nodes == 2)
		sort_two(a);
	if (a->nodes == 3)
		sort_three(a);
	if (a->nodes > 3 && a->nodes <= 5 && !check_order(a))
		sort_four_five(a, b);
	if (a->nodes > 5)
		algorithmic_sort(a, b, tree);
}
