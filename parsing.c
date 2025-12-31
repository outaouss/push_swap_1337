#include "push_swap.h"

void	stack_add_back(t_node **stack, t_node *to_add)
{
	t_node	*last;

	if (!stack || !to_add)
		return;
	if (!*stack)
	{
		*stack = to_add;
		return;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = to_add;
	to_add->previous = last;
}

t_node	*create_node(long value, t_node **stack)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_exit(stack);
	new_node->value = value;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void	fill_stack_a(t_node **stack_a, char **av)
{
	int		i;
	long	result;
	t_node	*new_node;

	i = 0;
	result = 0;
	if (!av || !av[0])
		error_exit_av(stack_a, av);
	while (av[i] != NULL)
	{
		result = ft_atoi(av[i], stack_a, av);
		has_duplicated(*stack_a, result, av);
		new_node = create_node(result, stack_a);
		stack_add_back(stack_a, new_node);
		i++;
	}
}
