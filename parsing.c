#include "push_swap.h"

void stack_add_back(t_node **stack, t_node *to_add)
{
	t_node  *last;

	if (!stack || !to_add)
		return ;
	if (!*stack)
	{
		*stack = to_add;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = to_add;
	to_add->previous = last;
}

t_node *create_node(long value, t_node **stack)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_exit(stack);
	new_node->value = value;
	new_node->next = NULL;
	new_node->previous = NULL;
	return new_node;
}

void fill_stack_a(t_node **stack_a, char **av)
{
	int i = 0;
	long result = 0;
	t_node *new_node;

	if (!av || !av[0])
		error_exit(stack_a);
	while (av[i] != NULL)
	{
	   result = ft_atoi(av[i], stack_a);
	   has_duplicated(*stack_a, result);
	   new_node = create_node(result, stack_a);
	   stack_add_back(stack_a, new_node);
	   i++;
	}
}
