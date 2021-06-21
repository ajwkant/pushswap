/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double_op.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 12:31:12 by akant         #+#    #+#                 */
/*   Updated: 2021/06/08 14:14:37 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_dlist *a, t_dlist *b)
{
	swap(a);
	swap(b);
}

void	rotate_ab(t_dlist *a, t_dlist *b)
{
	rotate(a);
	rotate(b);
}

void	rev_rotate_ab(t_dlist *a, t_dlist *b)
{
	rev_rotate(a);
	rev_rotate(b);
}
