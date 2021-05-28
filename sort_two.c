#include "push_swap.h"

int	sort_two(t_dlist *a)
{
	if (a->first->content > a->last->content)
	{
		swap(a);
		write_and_count("sa\n", 3);
	}
	return (1);
}
