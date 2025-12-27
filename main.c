#include "push_swap.h"

void print_index(t_node *head)
{
    while (head)
    {
        printf("%d\n", head->index);
        head = head->next;
    }
}
int main(int ac, char **av)
{
	t_node *stack_a;
	char **args;
	int j = 1;

	stack_a = NULL;
	if (ac < 2)
		return 0;
	while (av[j])
	{
		args = ft_split(av[j], ' ');
		fill_stack_a(&stack_a, args);
		free_matrix(args);
		j++;
	}
    // assign_index(stack_a);
	print_stack(stack_a);
	// print_index(stack_a);
	free_stack(&stack_a);
	return (0);
}