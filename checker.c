/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outaouss <outaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:35:42 by outaouss          #+#    #+#             */
/*   Updated: 2026/01/04 15:13:48 by outaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	executed_cmd(char *cmd, t_node **a, t_node **b)
{
	if (ft_strcmp(cmd, "sa\n") == 0)
		sa(a, 1);
	else if (ft_strcmp(cmd, "sb\n") == 0)
		sb(b, 1);
	else if (ft_strcmp(cmd, "ss\n") == 0)
		ss(a, b, 1);
	else if (ft_strcmp(cmd, "pa\n") == 0)
		pa(a, b, 1);
	else if (ft_strcmp(cmd, "pb\n") == 0)
		pb(a, b, 1);
	else if (ft_strcmp(cmd, "ra\n") == 0)
		ra(a, 1);
	else if (ft_strcmp(cmd, "rb\n") == 0)
		rb(b, 1);
	else if (ft_strcmp(cmd, "rr\n") == 0)
		rr(a, b, 1);
	else if (ft_strcmp(cmd, "rra\n") == 0)
		rra(a, 1);
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		rrb(b, 1);
	else if (ft_strcmp(cmd, "rrr\n") == 0)
		rrr(a, b, 1);
	else
		return (-1);
	return (0);
}

void	checker_loop(t_node **a, t_node **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (executed_cmd(line, a, b) == -1)
		{
			free(line);
			free_stack(a);
			free_stack(b);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(line);
	}
	if (is_sorted(*a) && *b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;
	int		j;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	j = 1;
	while (av[j])
	{
		args = ft_split(av[j], ' ');
		fill_stack_a(&stack_a, args);
		free_matrix(args);
		j++;
	}
	assign_index(stack_a);
	checker_loop(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
