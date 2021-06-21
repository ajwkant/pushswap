/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 14:21:08 by akant         #+#    #+#                 */
/*   Updated: 2021/06/15 14:24:32 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_input(int argc, char **argv, t_dlist *a, t_tree **tree)
{
	int		i;
	int		num;
	t_tree	*treenode;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[argc - i]);
		if ((num == 0 || num == -1)
			&& !(!ft_strcmp(argv[argc - i], "-1")
				|| !ft_strcmp(argv[argc - i], "0")))
			free_list_tree(*tree, a, 1);
		node = new_node(num);
		if (!node)
			free_list_tree(*tree, a, 1);
		treenode = tree_add(tree, num);
		if (!treenode)
		{
			free(node);
			free_list_tree(*tree, a, 1);
		}
		list_push(a, node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	t_tree	*tree;

	a = list_init();
	if (!a)
		error_function();
	b = list_init();
	if (!b)
		free_list_tree(NULL, a, 0);
	read_input(argc, argv, a, &tree);
	if (!tree)
		error_function();
	sorting(a, b, &tree);
	clear_stacklist(a);
	free_list_tree(tree, b, 0);
	return (0);
}
