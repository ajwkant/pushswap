#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "get_next_line.h"

int		ft_atoi(const char *str);

typedef struct	s_node
{
	int				content;
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
int	push_a(t_dlist *a, t_dlist *b);
int	push_b(t_dlist *a, t_dlist *b);
int	rotate(t_dlist *list);
int	rev_rotate(t_dlist *list);
// List utils 3
void	clear_stacklist(t_dlist *list);
int		check_order(t_dlist *list);
// Error
int	error_function(char *string, int errno);

