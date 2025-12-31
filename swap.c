#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*seconde;

	if (!*stack || !(*stack)->next)
		return ;

	first = *stack;
	seconde = first->next;

	first->next = seconde->next;
	first->previous = seconde;

	if (seconde->next)
		seconde->next->previous = first;

	seconde->next = first; 
	seconde->previous = NULL;
	
	*stack = seconde;
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
