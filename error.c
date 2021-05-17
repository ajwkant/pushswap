#include "push_swap.h"

int	error_function(char *string, int errno)
{
	write(2, string, ft_strlen(string));
	return (errno);
}
