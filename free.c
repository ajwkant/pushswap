/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 11:27:20 by akant         #+#    #+#                 */
/*   Updated: 2021/06/08 11:43:26 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list_tree(t_tree *tree, t_dlist *a, int error)
{
	free_tree(tree);
	clear_stacklist(a);
	if (error)
		error_function();
}
