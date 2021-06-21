/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 14:02:24 by akant         #+#    #+#                 */
/*   Updated: 2021/06/15 14:05:05 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct s_tree
{
	int				content;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_dlist
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
void	swap(t_dlist *list);
void	push_list(t_dlist *a, t_dlist *b);
void	rotate(t_dlist *list);
void	rev_rotate(t_dlist *list);
void	remove_from_list(t_dlist *list, int a);
// List utils 3
void	clear_stacklist(t_dlist *list);
int		check_order(t_dlist *list);
int		find_pos(t_dlist *list, int find);
// Error
void	error_function(void);
// Tree
t_tree	*tree_new_node(int a);
t_tree	*tree_add(t_tree **tree, int a);
void	print_tree(t_tree *tree);
void	free_tree(t_tree *tree);
// Sorting
void	sort_three(t_dlist *a);
void	sorting(t_dlist *a, t_dlist *b, t_tree **tree);
// Sort_two
void	sort_two(t_dlist *a);

// Sort three
void	sort_three_sa(t_dlist *a);
void	sort_three_sarra(t_dlist *a);
void	sort_three_sara(t_dlist *a);
void	sort_three_ra(t_dlist *a);
void	sort_three(t_dlist *a);

// Tree functionality
t_tree	*tree_get_smallest(t_tree **tree);
t_dlist	*find_chunk(t_tree **tree, int c);

// Algorithmic sort
int		algorithmic_sort(t_dlist *a, t_dlist *b, t_tree **tree);

// Chunksort
int		find_cheapest_direction(t_dlist *a, t_dlist *chunk);
void	rotate_before_push(t_dlist *a, t_dlist *b, int pos, int num);
void	chunk_sort(t_dlist *a, t_dlist *b, t_tree **tree, int chunksize);

// Free
void	free_list_tree(t_tree *tree, t_dlist *a, int error);

// Direction
int		find_cheapest_direction(t_dlist *a, t_dlist *chunk);
int		find_first_num(t_dlist *a, t_dlist *chunk,
			int direction, int *cheapest_pos);
void	rotate_b_correctly(t_dlist *b, int num);

// List_remove
void	remove_from_list(t_dlist *list, int a);

// Double_op
void	swap_ab(t_dlist *a, t_dlist *b);
void	rotate_ab(t_dlist *a, t_dlist *b);
void	rev_rotate_ab(t_dlist *a, t_dlist *b);

// Rotate
void	insert_after_first(t_dlist *a, t_dlist *b);
void	insert_after_second(t_dlist *a, t_dlist *b);
void	insert_after_third(t_dlist *a, t_dlist *b);
void	rotate_a(t_dlist *a);
void	rev_rotate_a(t_dlist *a);
#endif
