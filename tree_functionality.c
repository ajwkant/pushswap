#include "push_swap.h"

t_tree	*smaller(t_tree *tree)
{
	t_tree	*temp;

	if (tree->left->left)
		return (smaller(tree->left));
	else if (tree->left->right)
	{
		temp = tree->left;
		tree->left = temp->right;
		return (temp);
	}
	else// if (tree->left) dit moet altijd gebeuren als het goed is
	{
		temp = tree->left;
		tree->left = NULL;
		return (temp);
	}
}

t_tree	*remove_parent(t_tree **tree)
{
	t_tree	*temp;

	temp = *tree;
	*tree = temp->right;
	return (temp);
}

t_tree	*tree_get_smallest(t_tree **tree) // --- Check wether remove parent is the last node oid
{
	t_tree	*temp;

	if (*tree && (*tree)->left && (*tree)->left->left)
		return (smaller((*tree)->left));
	else if (tree && (*tree)->left && (*tree)->left->right)
	{
		temp = (*tree)->left;
		(*tree)->left = temp->right;
		return (temp);
	}
	else if (*tree && (*tree)->left)
	{
		temp = (*tree)->left;
		(*tree)->left = NULL;
		return (temp);
	}
	else
		return (remove_parent(tree));
}

t_dlist	*find_chunk(t_tree **tree, int c)
{
	t_dlist	*list;
	t_node	*node;
	int		lowest;

	list = list_init();
	if (!list)
		return (NULL);
	while (c)
	{
		lowest = tree_get_smallest(tree);
		node = new_node(lowest);
		if (!node)
			return (NULL);
		list_push(list, node);
		c--;
	}
	return (list);
}
