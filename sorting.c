#include "push_swap.h"

int	sort_two(t_dlist *a)
{
	if (a->first->content > a->last->content)
		swap(a);
	return (1);
}

int	sort_three(t_dlist *a)
{
	if (a->first->content < a->first->next->content &&
		a->first->next->content < a->last->content)
		return ;
	if (a->first->content > a->first->next->content &&
		a->first->content < a->last->content)
		return (swap(a));
	if (a->first > a->first->next->content &&
		a->first->next->content >  a->last->content)
	{
		swap(a);
		return (rev_rotate(a));
	}
	if (a->first->content > a->last->content &&
		a->first->next->content < a->last->content)
		return (rotate(a));
	if (a->first < a->last->content &&
		a->first->next->content >  a->last->content)
	{
		swap(a);
		return (rotate(a));
	}
	if (a->first < a->first->next->content &&
		a->first->content >  a->last->content)
		return (rev_rotate(a));
	return (0);
}

int	sorting(t_dlist *a, t_dlist *b)
{
	if (a->nodes == 1)
		return (1);
	if (a->nodes == 2)
		return (sort_two(a));
	if (a->nodes == 3)
		return (sort_three(a));
	if (a->nodes > 3 && a->nodes <= 5)
		return ()

}
