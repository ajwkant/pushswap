#include "push_swap.h"

int		g_instructions;

int		main(int argc, char **argv)
{
	int		i;
	// t_dlist	*index_list;
	t_tree	*tree;
	t_dlist	*a;
	t_dlist	*b;
	t_node	*node;
	int		num;
	t_tree	*treenode;

	// checkinput();
	// index_list = list_init();
	a = list_init(); // check returnvalue
	b = list_init();
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[argc - i]);
		node = new_node(num); // check returnvalue
		// node->index = i - 1;
		treenode = tree_add(&tree, num);
		if (!num || !treenode) // ------------ num can actually be 0
			return (-1); // free etc
		list_push(a, node);
		i++;
	}
	// print_tree(tree);
	// printf("\n");
	// free_tree(tree);
	// printf("\n");
	// printf("\n Original stack \n");
	// print_list(a);
	// printf("\n--------------\n");
	sorting(a, b, &tree);
	// printf("Instructions: %d\n", g_instructions);

	// Print van laag naar hoog uit vanuit de tree en rebalance
	// treenode = tree_get_smallest(&tree);
	// printf("node content: %d\n", treenode->content);
	// treenode = tree_get_smallest(&tree);
	// printf("node content: %d\n", treenode->content);
	// treenode = tree_get_smallest(&tree);
	// printf("node content: %d\n", treenode->content);
	// treenode = tree_get_smallest(&tree);
	// printf("node content: %d\n", treenode->content);
	// treenode = tree_get_smallest(&tree);
	// printf("node content: %d\n", treenode->content);
	// treenode = tree_get_smallest(&tree);
	// printf("node content: %d\n", treenode->content);
	// treenode = tree_get_smallest(&tree);
	// printf("node content: %d\n", treenode->content);
	// treenode = tree_get_smallest(&tree);
	// printf("node content: %d\n", treenode->content);
	// treenode = tree_get_smallest(&tree);
	// printf("node content: %d\n", treenode->content);
	// treenode = tree_get_smallest(&tree);
	// printf("node content: %d\n", treenode->content);
	// // treenode = tree_get_smallest(&tree);
	// // printf("node content: %d\n", treenode->content);
	// printf("TEST\\n\n");
	// printf("\n Instructions: %d\n", g_instructions);
	printf("\n Stack A: \n");
	print_list(a);
	// printf("\n Stack B: \n");
	// print_list(b);
	// printf("\nIn order: %d\n", check_order(a)); // Misschien de order aanpassen
	clear_stacklist(a);
	clear_stacklist(b);
	free_tree(tree);
	// system("leaks a.out");
	return (0);
}
