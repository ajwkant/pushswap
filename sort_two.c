#include "push_swap.h"

void	sort_two(t_dlist *a)
{
	if (a->first->content > a->last->content)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
}
