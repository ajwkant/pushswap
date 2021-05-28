#include "push_swap.h"

int	sort_three_sa(t_dlist *a)
{
	write_and_count("sa\n", 3);
	return (swap(a));
}

int	sort_three_sarra(t_dlist *a)
{
	swap(a);
	write_and_count("sa\nrra\n", 7);
	return (rev_rotate(a));
}

int	sort_three_sara(t_dlist *a)
{
	swap(a);
	write_and_count("sa\nra\n", 6);
	return (rotate(a));
}

int	sort_three_ra(t_dlist *a)
{
	write_and_count("ra\n", 3);
	return (rotate(a));
}

int	sort_three(t_dlist *a)
{
	if (a->first->content < a->first->next->content &&
		a->first->next->content < a->last->content)
		return (1);
	if (a->first->content > a->first->next->content &&
		a->first->content < a->last->content)
		return (sort_three_sa(a));
	if (a->first->content > a->first->next->content &&
		a->first->next->content >  a->last->content)
		return (sort_three_sarra(a));
	if (a->first->content > a->last->content &&
		a->first->next->content < a->last->content)
		return (sort_three_ra(a));
	if (a->first->content < a->last->content &&
		a->first->next->content >  a->last->content)
	return (sort_three_sara(a));
	if (a->first->content < a->first->next->content &&
		a->first->content >  a->last->content)
	{
		write_and_count("rra\n", 4);
		return (rev_rotate(a));
	}
	return (0);
}
