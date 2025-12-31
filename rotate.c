#include "push_swap.h"

t_node	*find_last_node(t_node *lst)
{
	if (!lst)
		return (NULL);
	while ((lst)->next)
	{
		(lst) = (lst)->next;
	}
	return (lst);
}

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last_node(*stack);

	*stack = first->next;
	(*stack)->previous = NULL;

	last->next = first;
	first->previous = last;
	first->next = NULL;
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

// void	print_stack(t_node *head)
// {
// 	while (head)
// 	{
// 		printf("%d\n", head->value);
// 		head = head->next;
// 	}
// }