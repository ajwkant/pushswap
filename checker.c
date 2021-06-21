/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 12:31:12 by akant         #+#    #+#                 */
/*   Updated: 2021/06/15 13:59:49 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_operation(char *line, t_dlist *a, t_dlist *b)
{
	if (!ft_strcmp(line, "sa"))
		swap(a);
	else if (!ft_strcmp(line, "sb"))
		swap(b);
	else if (!ft_strcmp(line, "ss"))
		swap_ab(a, b);
	else if (!ft_strcmp(line, "pa"))
		push_list(b, a);
	else if (!ft_strcmp(line, "pb"))
		push_list(a, b);
	else if (!ft_strcmp(line, "ra"))
		rotate(a);
	else if (!ft_strcmp(line, "rb"))
		rotate(b);
	else if (!ft_strcmp(line, "rr"))
		rotate_ab(a, b);
	else if (!ft_strcmp(line, "rra"))
		rev_rotate(a);
	else if (!ft_strcmp(line, "rrb"))
		rev_rotate(b);
	else if (!ft_strcmp(line, "rrr"))
		rev_rotate_ab(a, b);
	else
		error_function();
}

void	read_numbers(int argc, char **argv, t_dlist *a)
{
	int			i;
	long int	num;
	t_node		*node;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[argc - i]);
		if ((num == 0 || num == -1)
			&& (!(!ft_strcmp(argv[argc - i], "-1")
					|| !ft_strcmp(argv[argc - i], "0"))))
			free_list_tree(NULL, a, 1);
		if (find_pos(a, num) > 0 || (a->first && a->first->content == num))
			free_list_tree(NULL, a, 1);
		node = new_node(num);
		if (!node)
			free_list_tree(NULL, a, 1);
		list_push(a, node);
		i++;
	}
}

int	check_input(int argc, char **argv, t_dlist	*a, t_dlist	*b)
{
	char	*line;
	int		ret;

	read_numbers(argc, argv, a);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ret == -1)
			error_function();
		if (!ret)
			break ;
		find_operation(line, a, b);
		free(line);
	}
	if (check_order(a) && !b->first)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_stacklist(a);
	clear_stacklist(b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;

	if (argc == 1)
		return (1);
	a = list_init();
	if (!a)
		error_function();
	b = list_init();
	if (!b)
	{
		clear_stacklist(a);
		error_function();
	}
	return (check_input(argc, argv, a, b));
}
