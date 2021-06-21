/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 14:24:26 by akant         #+#    #+#                 */
/*   Updated: 2021/06/08 14:24:30 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_after_first(t_dlist *a, t_dlist *b)
{
	push_list(b, a);
	swap(a);
	write(1, "pa\nsa\n", 6);
}

void	insert_after_second(t_dlist *a, t_dlist *b)
{
	rotate(a);
	push_list(b, a);
	swap(a);
	rev_rotate(a);
	write(1, "ra\npa\nsa\nrra\n", 13);
}

void	insert_after_third(t_dlist *a, t_dlist *b)
{
	rev_rotate(a);
	push_list(b, a);
	write(1, "rra\npa\n", 7);
}

void	rotate_a(t_dlist *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rev_rotate_a(t_dlist *a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}
