#include "push_swap.h"

void	sort_three(t_node **stack)
{
	t_node	*big_index;

	big_index = find_max_index(*stack);
	if (big_index->previous == NULL)
		ra(stack);
	else if (big_index->next != NULL)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	t_node	*min_index;

	while (stack_len(*stack_a) > 3)
	{
		min_index = find_min_index(*stack_a);
		if (min_index->previous == NULL)
			pb(stack_a, stack_b);
		else if (min_index->next == NULL || min_index->next->next == NULL)
			rra(stack_a);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	k_sort_phase1(t_node **stack_a, t_node ** stack_b)
{
	int	len;
	int	range;
	int	i;

	i = 0;
	len = stack_len(*stack_a);
	range = (len <= 100) ? 16 : 48;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (i + range))
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	k_sort_phase2(t_node **stack_a, t_node **stack_b)
{
	t_node	*max_index;
	int		pos;

	while (*stack_b)
	{
		max_index = find_max_index(*stack_b);
		pos = get_position(*stack_b, max_index);
		while(*stack_b != max_index)
		{
			if ((*stack_b)->index == max_index->index - 1)
				pa(stack_a, stack_b);
			else if (pos <= stack_len(*stack_b) / 2)
				rb(stack_b);

			else
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		if (*stack_a && (*stack_a)->next && (*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
	}
}
