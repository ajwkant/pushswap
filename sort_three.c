#include "push_swap.h"

void	sort_three_sa(t_dlist *a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	sort_three_sarra(t_dlist *a)
{
	swap(a);
	write(1, "sa\nrra\n", 7);
	rev_rotate(a);
}

void	sort_three_sara(t_dlist *a)
{
	swap(a);
	write(1, "sa\nra\n", 6);
	rotate(a);
}

void	sort_three_ra(t_dlist *a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

void	sort_three(t_dlist *a)
{
	if (a->first->content < a->first->next->content
		&& a->first->next->content < a->last->content)
		return ;
	if (a->first->content > a->first->next->content
		&& a->first->content < a->last->content)
		sort_three_sa(a);
	if (a->first->content > a->first->next->content
		&& a->first->next->content > a->last->content)
		sort_three_sarra(a);
	if (a->first->content > a->last->content
		&& a->first->next->content < a->last->content)
		sort_three_ra(a);
	if (a->first->content < a->last->content
		&& a->first->next->content > a->last->content)
		sort_three_sara(a);
	if (a->first->content < a->first->next->content
		&& a->first->content > a->last->content)
	{
		write(1, "rra\n", 4);
		rev_rotate(a);
	}
}
