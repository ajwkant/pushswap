/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 12:31:12 by akant         #+#    #+#                 */
/*   Updated: 2021/05/17 13:35:38 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_operation(char *line, t_dlist *a, t_dlist *b)
{
	if (!ft_strcmp(line, "sa"))
		return (swap(a));
	if (!ft_strcmp(line, "sb"))
		return (swap(b));
	if (!ft_strcmp(line, "ss"))
		return (swap(a) && swap(b));
	if (!ft_strcmp(line, "pa"))
		return (push_a(a, b));
	if (!ft_strcmp(line, "pb"))
		return (push_b(a, b));
	if (!ft_strcmp(line, "ra"))
		return (rotate(a));
	if (!ft_strcmp(line, "rb"))
		return (rotate(b));
	if (!ft_strcmp(line, "rr"))
		return (rotate(a) && rotate(b));
	if (!ft_strcmp(line, "rra"))
		return (rev_rotate(a));
	if (!ft_strcmp(line, "rrb"))
		return (rev_rotate(b));
	if (!ft_strcmp(line, "rrr"))
		return (rev_rotate(a) && rev_rotate(b));
	return (error_function("Operation error\n", -1));
}

int		check_isdigit(char *string)
{
	while (*string)
	{
		if (!ft_isdigit(*string))
			return (0);
		string++;
	}
	return (1);
}

int		read_numbers(int argc, char **argv, t_dlist *a)
{
	int		i;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		if (!check_isdigit(argv[i]))
			return (error_function("Not a valid number\n", -1));
		node = new_node(ft_atoi(argv[i])); // check returnvalue
		if (!node)
			return (error_function("Node making failed\n", -1));
		list_push(a, node);
		i++;
	}
	return (1);
}

int		is_empty(t_dlist *b)
{
	if (b->first == NULL)
		return (1);
	return (0);
}

int		check_input(int argc, char **argv, t_dlist	*a, t_dlist	*b)
{
	char	*line;
	int		ret;

	ret = read_numbers(argc, argv, a);
	if (ret == -1)
		return (ret);
	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		printf("loopje\n");
		find_operation(line, a, b);
		free(line);
		if (ret == 0)
			break ;
		ret = get_next_line(0, &line);
	}
	free(line);
	if (ret == -1)
		return (error_function("Error reading instructions", -1));
	// printf("\n-------\n");
	// print_list(a);
	// printf("-------\n");
	// print_list(b);
	if (check_order(a) && is_empty(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	// printf("In order: %d\n", check_order(a));
	clear_stacklist(a);
	clear_stacklist(b);
	return (1);

}

int		main(int argc, char **argv) // stop when there's an operation error
{
	t_dlist	*a;
	t_dlist	*b;

	if (argc == 1)
		return (1);
	a = list_init();
	if (!a)
	{
		return (-1);
		write(2, "Error\n", 6);
	}
	b = list_init();
	if (!b)
	{
		return (-1);
		write(2, "Error\n", 6);
	}
	return (check_input(argc, argv, a, b));
}
