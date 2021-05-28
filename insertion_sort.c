#include "push_swap.h"

// 1. Find a number from up and a number from down that's one of the smallest 3 numbers
// 2. Push that number to stack b on the right spot and find the 3 smallest again

void	get_first_three_lowest(t_dlist *a, int *lowest, int *sec, int *third)
{
	*lowest = a->first->content;
	if (a->first->next->content > *lowest)
		*sec = a->first->next->content;
	else
	{
		*sec = *lowest;
		*lowest = a->first->next->content;
	}
	if (a->first->next->next->content < lowest)
	{
		*third = *sec;
		*sec = *lowest;
		*lowest = a->first->next->next->content;
	}
	else if (a->first->next->next->content < sec)
	{
		*third = *sec;
		*sec = a->first->next->next->content;
	}
	else
		*third = a->first->next->next->content;
}

void	lowest_values_changer(t_dlist *a, int value, int *lowest, int *sec, int *third)
{
	if (value < *lowest)
	{
		*third = *sec;
		*sec = *lowest;
		*lowest = value;
	}
	else if (value < *sec)
	{
		*third = *sec;
		*sec = *value;
	}
	else
		*third = value;
}

int	find_lowest(t_dlist *a, t_dlist *b)
{
	int lowest;
	int sec;
	int third;
	int i;
	t_node *current;

	get_first_three_lowest(a, &lowest, &sec, &third);
	i = a->nodes;
	current = a->first->next->next->next;
	while (i - 3)
	{
		if (current->content < third)
			lowest_values_changer(a, current->content, &lowest, &sec, &third);
		i--;
	}
}
