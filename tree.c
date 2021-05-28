#include "push_swap.h"

t_tree	*tree_new_node(int a)
{
	t_tree *new;

	new = malloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	new->content = a;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_tree	*tree_add_rec(t_tree *tree, int a)
{
	if (a < tree->content)
	{
		if (tree->left == NULL)
		{
			tree->left = tree_new_node(a);
			return (tree->left);
		}
		else
			return (tree_add_rec(tree->left, a));
	}
	else if (a > tree->content)
	{
		if (tree->right == NULL)
		{
			tree->right = tree_new_node(a);
			return (tree->right);
		}
		else
			return (tree_add_rec(tree->right, a));
	}
	return (0);
}

t_tree	*tree_add(t_tree **tree, int a)
{
	if (!*tree)
		*tree = tree_new_node(a);
	else
		return (tree_add_rec(*tree, a));
	return (*tree);
}

void	print_tree(t_tree *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		print_tree(tree->left);
	printf("%d ", tree->content);
	if (tree->right)
		print_tree(tree->right);
}

void	free_help(t_tree *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		free_help(tree->left);
	free(tree);
	if (tree->right)
		free_help(tree->right);
}

void	free_tree(t_tree *tree)
{
	if (tree)
	{
		if (tree->left)
			free_help(tree->left);
		if (tree->right)
			free_help(tree->right);
		free(tree);
	}
}
