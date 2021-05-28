#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "get_next_line.h"

extern int		g_instructions;

typedef struct	s_tree
{
	int				content;
	// int				index;
	struct	s_tree	*left;
	struct	s_tree	*right;
}					t_tree;

typedef struct	s_node
{
	int				content;
	// int				index;
	struct	s_node	*next;
	struct	s_node	*prev;
}					t_node;

typedef struct	s_dlist
{
	t_node		*first;
	t_node		*last;
	int			nodes;
}				t_dlist;

// List utils 1
t_dlist	*list_init(void);
t_node	*new_node(int x);
void	list_push(t_dlist *list, t_node *node);
t_node	*list_pop(t_dlist *list);
void	print_list(t_dlist *list);
// List utils 2
int	swap(t_dlist *list);
int	push_list(t_dlist *a, t_dlist *b);
int	rotate(t_dlist *list);
int	rev_rotate(t_dlist *list);
// List utils 3
void	clear_stacklist(t_dlist *list);
int		check_order(t_dlist *list);
int		find_pos(t_dlist *list, int find);
// Error
int	error_function(char *string, int errno);
// Tree
t_tree	*tree_new_node(int a);
t_tree	*tree_add(t_tree **tree, int a);
void	print_tree(t_tree *tree);
void	free_tree(t_tree *tree);
// Sorting

int	sort_three(t_dlist *a);
int	sorting(t_dlist *a, t_dlist *b, t_tree **tree);
// Sort_two
int	sort_two(t_dlist *a);
// Sort three
int	sort_three_sa(t_dlist *a);
int	sort_three_sarra(t_dlist *a);
int	sort_three_sara(t_dlist *a);
int	sort_three_ra(t_dlist *a);
int	sort_three(t_dlist *a);


// Tree functionality
t_tree	*tree_get_smallest(t_tree **tree);
// Algorithmic sort
int		algorithmic_sort(t_dlist *a, t_dlist *b, t_tree **tree);
void	write_and_count(char *string, int len); // betere plek voor zoeken