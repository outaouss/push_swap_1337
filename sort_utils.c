#include "push_swap.h"

void	assign_index(t_node *stack)
{
	int		count;
	t_node	*compare;
	t_node	*current;

	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		count = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}

int	is_sorted(t_node *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_len(t_node *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	get_position(t_node *stack, t_node *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}
