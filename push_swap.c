#include "push_swap.h"

// Functie voor clear list

int		main(int argc, char **argv)
{
	int		i;
	t_dlist	*a;
	t_dlist	*b;
	t_node	*node;

	// checkinput();
	a = list_init(); // check returnvalue
	b = list_init();
	i = 1;
	while (i < argc)
	{
		node = new_node(ft_atoi(argv[i])); // check returnvalue
		list_push(a, node);
		i++;
	}
	// push_b(a, b);
	// push_b(a, b);
	// push_b(a, b);
	// rotate(a);
	// rev_rotate(a);
	// swap(a);
	// swap(a);
	// list_pop(list);
	// node = new_node(100);
	// list_push(list, node);
	// node = list_pop(list);
	// printf("%d\n", node->content);
	// node = list_pop(list);
	// printf("%d\n", node->content);
	// node = list_pop(list);
	// printf("%d\n", node->content);
	// node = list_pop(list);
	// printf("%d\n", node->content);

	print_list(a);
	printf("\n-------\n");
	print_list(b);
	printf("In order: %d\n", check_order(a));
	clear_stacklist(a);
	clear_stacklist(b);
	// system("leaks a.out");
	return (0);
}
