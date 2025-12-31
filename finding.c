#include "push_swap.h"

t_node	*find_max_index(t_node *stack)
{
	t_node	*big_index;

	if (!stack)
		return (NULL);
	big_index = stack;
	while (stack)
	{
		if (stack->index > big_index->index)
			big_index = stack;
		stack = stack->next;
	}
	return (big_index);
}

t_node	*find_min_index(t_node *stack)
{
	t_node	*min_index;

	if (!stack)
		return (NULL);
	min_index = stack;
	while (stack)
	{
		if (stack->index < min_index->index)
			min_index = stack;
		stack = stack->next;
	}
	return (min_index);
}
