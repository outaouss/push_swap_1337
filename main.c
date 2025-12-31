#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;
	int		j;

	j = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return 0;
	while (av[j])
	{
		args = ft_split(av[j], ' ');
		fill_stack_a(&stack_a, args);
		free_matrix(args);
		j++;
	}
	assign_index(stack_a);
	if (!(is_sorted(stack_a)) && stack_len(stack_a) > 1)
	{
		if (stack_len(stack_a) == 2)
				sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else if (stack_len(stack_a) <= 5)
			sort_five(&stack_a, &stack_b);
		else
		{
			k_sort_phase1(&stack_a, &stack_b);
			k_sort_phase2(&stack_a, &stack_b);
		}
	}
	// print_stack(stack_a);
	free_stack(&stack_a);
	return (0);
}
